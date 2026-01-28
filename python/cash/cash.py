change = 0
while (True):
    try:

        change = (float(input("Change: ")))
        if change > 0:
            break
    except ValueError:
        continue
cents = int(round(change * 100))
coins = 0
denominations = [25, 10, 5, 1]
# Why do it the hard way when you can just use for loop 😛

for coin in denominations:
    coins += cents // coin
    cents = cents % coin

print(coins)









# Original solution. Works but lenghty
# coins = cents//25
# cents = cents % 25

# coins += cents//10
# cents = cents % 10

# coins += cents//5
# cents = cents % 5

# coins += cents//1
# cents = cents % 1
