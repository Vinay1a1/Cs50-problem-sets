cardNum_str = 0
while (True):
    try:

        cardNum_str = input("Number: ")
        if cardNum_str.isdigit() :
            cardNum =int(cardNum_str)
            break
        else:
            continue
    except ValueError:
        continue


if len(cardNum_str) == 15 and cardNum_str[:2] in ["34", "37"]:
    brand = "AMEX"
elif len(cardNum_str) == 16 and int(cardNum_str[:2]) in range(51,56):
    brand = "MASTERCARD"
elif (len(cardNum_str) == 13 or len(cardNum_str) == 16) and cardNum_str[0] == "4":
    brand = "VISA"
else:
    brand = "INVALID"

total = 0
reverse_cardNum = cardNum_str[::-1]
for i in range(len(cardNum_str)):
    digit = int(reverse_cardNum[i])
    if i % 2 == 1:
        product = digit * 2
        total += (product // 10) + (product % 10)
    else:
        total += digit
if total % 10 == 0:
    print(brand)
else:
    print("INVALID")



