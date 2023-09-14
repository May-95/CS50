isNum = False
change = 0
while not isNum:
    try:
        change = float(input("Change owed: "))
        if change < 0:
            isNum = False
        else:
            break
    except ValueError:
        isNum = False

count = 0

if change >= 0.25:
    quarters = int(change / 0.25)
    change = round(change - (0.25 * quarters), 2)
    count += quarters
if change >= 0.10:
    dimes = int(change / 0.10)
    change = round(change - (0.10 * dimes), 2)
    count += dimes
if change >= 0.05:
    nickels = int(change / 0.05)
    change = round(change - (0.05 * nickels), 2)
    count += nickels
if change >= 0.01:
    pennies = int(change / 0.01)
    change = round(change - (0.01 * pennies), 2)
    count += pennies
print(count)
print()
