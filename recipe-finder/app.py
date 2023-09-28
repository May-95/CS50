from flask import Flask, redirect, render_template, request
import requests
import config

app = Flask(__name__)
key = "&app_id={}&app_key={}&".format(config.ID, config.API_KEY)


@app.route("/", methods=["GET"])
def home():
    return render_template("homepage.html")


@app.route("/recipes", methods=["GET", "POST"])
def recipes():
    if request.method == "GET":
        return redirect("/")
    search = request.form.get('search').replace(" ", "%20")
    diet = request.form.get('diet')
    health = request.form.get('health')
    cuisineType = request.form.get('cuisineType')
    mealType = request.form.get('mealType')
    dishType = request.form.get('dishType')

    options = {
        'diet': diet,
        'health': health,
        'cuisineType': cuisineType,
        'mealType': mealType,
        'dishType': dishType
    }

    url = "https://api.edamam.com/api/recipes/v2?type=public&q=" + search + key
    data = requests.get(url, params=options)
    if not data:
        return redirect("/")
    else:
        list_of_recipes = format_data(data.json()['hits'])
        return render_template("recommendations.html", list_of_recipes=list_of_recipes)


def format_data(jsonData):
    recipes = []
    for data in jsonData:
        current_recipe = {}
        current_recipe['name'] = data['recipe']['label']
        current_recipe['image'] = data['recipe']['images']['REGULAR']['url']
        current_recipe['url'] = data['recipe']['url']
        current_recipe['ingredients'] = len(data['recipe']['ingredientLines'])
        current_recipe['cuisineType'] = ", ".join(
            data['recipe']['cuisineType']).title()
        recipes.append(current_recipe)
    return recipes[:9]


if __name__ == '__main__':
    app.run(host='localhost', port=5000)
