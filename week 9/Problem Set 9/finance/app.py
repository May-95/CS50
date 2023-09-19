import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash
import datetime

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    user_id = session["user_id"]
    user_info = db.execute(
        "SELECT name, symbol, shares FROM shares WHERE user_id=?", user_id
    )
    cash = db.execute("SELECT cash FROM users WHERE id=?", user_id)[0]["cash"]
    user_total = 0
    for share in user_info:
        share["price"] = float(lookup(share["symbol"])["price"])
        total = share["price"] * share["shares"]
        user_total += total
        share["total"] = usd(total)
        share["price"] = usd(share["price"])
    user_total = usd(user_total + cash)
    return render_template(
        "index.html", user_info=user_info, cash=usd(cash), user_total=user_total
    )


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    if request.method == "GET":
        return render_template("buy.html")
    stock = lookup(request.form.get("symbol"))
    if not stock:
        return apology("Invalid symbol", 400)
    try:
        requested_shares = float(request.form.get("shares"))
    except:
        return apology("Invalid shares", 400)
    if requested_shares < 0 or not requested_shares.is_integer():
        return apology("Invalid shares", 400)
    share_price = float(stock["price"])
    if not requested_shares or requested_shares < 1:
        return apology("Missing shares", 400)
    user_id = session["user_id"]
    price = float(share_price * requested_shares)
    cash = db.execute("SELECT cash FROM users WHERE id=?", user_id)[0]["cash"]
    if price > cash:
        return apology("Not enough money", 400)
    new_amount = cash - price
    db.execute("UPDATE users SET cash=? WHERE id=?", new_amount, user_id)
    db.execute(
        "INSERT INTO transactions(user_id, name, symbol, price, shares, date) VALUES(?, ?, ?, ?, ?, ?)",
        user_id,
        stock["name"],
        stock["symbol"],
        stock["price"],
        requested_shares,
        datetime.datetime.now(),
    )
    does_share_exist = db.execute(
        "select * from shares where user_id=? AND symbol=?", user_id, stock["symbol"]
    )
    if does_share_exist:
        db.execute(
            "UPDATE shares SET shares=shares+? WHERE user_id=? AND symbol=?",
            requested_shares,
            user_id,
            stock["symbol"],
        )
    else:
        db.execute(
            "INSERT INTO shares(user_id, name, symbol, shares) VALUES(?, ?, ?, ?)",
            user_id,
            stock["name"],
            stock["symbol"],
            requested_shares,
        )
    return redirect("/")


@app.route("/history")
@login_required
def history():
    user_id = session["user_id"]
    transactions = db.execute(
        "SELECT symbol, shares, price, date FROM transactions WHERE user_id=?", user_id
    )
    return render_template("history.html", transactions=transactions)


@app.route("/cash", methods=["GET", "POST"])
@login_required
def cash():
    if request.method == "GET":
        return render_template("cash.html")
    amount = float(request.form.get("amount"))
    if not amount:
        return apology("must provide amount", 400)
    if amount < 0:
        return apology("amount cannot be negative", 400)
    user_id = session["user_id"]
    db.execute("UPDATE users SET cash=cash+? WHERE id=?", amount, user_id)
    return redirect("/")


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 400)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 400)

        # Query database for username
        rows = db.execute(
            "SELECT * FROM users WHERE username = ?", request.form.get("username")
        )

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(
            rows[0]["hash"], request.form.get("password")
        ):
            return apology("invalid username and/or password", 400)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    if request.method == "GET":
        return render_template("quote.html")
    symbol = request.form.get("symbol")
    stock = lookup(symbol)
    if stock == "" or not stock:
        return apology("Invalid symbol", 400)
    price = usd(stock["price"])
    return render_template("quoted.html", stock=stock, price=price)


@app.route("/register", methods=["GET", "POST"])
def register():
    if request.method == "GET":
        return render_template("register.html")
    # Check user is not empty and username does not already exist
    username = request.form.get("username")
    username_exist = db.execute("SELECT username FROM users WHERE username=?", username)
    if username == "" or username_exist:
        return apology("invalid username", 400)

    # Check if password is the same and not blank
    password = request.form.get("password")
    confirmation = request.form.get("confirmation")
    if password == "" or confirmation == "" or not password == confirmation:
        return apology("invalid password, cannot be empty and must match", 400)
    hash = generate_password_hash(password)
    db.execute("INSERT INTO users (username, hash) VALUES(?,?)", username, hash)
    return redirect("/")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    user_id = session["user_id"]
    if request.method == "GET":
        symbols = db.execute("SELECT symbol FROM shares WHERE user_id=?", user_id)
        return render_template("sell.html", symbols=symbols)
    symbol = request.form.get("symbol")
    shares_to_sell = int(request.form.get("shares"))
    if symbol == "" or not symbol:
        return apology("invalid symbol", 400)
    elif not shares_to_sell:
        return apology("invalid shares", 400)
    current_shares = int(
        db.execute(
            "SELECT shares FROM shares WHERE user_id=? AND symbol=?", user_id, symbol
        )[0]["shares"]
    )
    if shares_to_sell > current_shares:
        return apology("Too many shares", 400)
    elif shares_to_sell < 1:
        return apology("Too little shares", 400)
    share_price = float(lookup(symbol)["price"])
    name = lookup(symbol)["name"]
    profit = share_price * shares_to_sell
    db.execute("UPDATE users SET cash=cash+? WHERE id=?", profit, user_id)
    if current_shares - shares_to_sell == 0:
        db.execute("DELETE FROM shares WHERE user_id=? AND symbol=?", user_id, symbol)
    else:
        db.execute(
            "UPDATE shares SET shares=shares-? WHERE user_id=? AND symbol=?",
            shares_to_sell,
            user_id,
            symbol,
        )
        db.execute(
            "INSERT INTO transactions(user_id, name, symbol, price, shares, date) VALUES(?, ?, ?, ?, ?, ?)",
            user_id,
            name,
            symbol,
            share_price,
            -abs(shares_to_sell),
            datetime.datetime.now(),
        )
    return redirect("/")
