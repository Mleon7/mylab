# TODO
from cs50 import get_float

def get_dollars():
    while True:
        dollars = get_float("Change owed: ")
        if dollars > 0:
            break
        else:
            print("negative number")
    return dollars

def calculate_cents(cents, cent):
    num = 1
    temp = cent
    while temp <= cents:
        num += 1
        temp = cent * num 
    return num - 1


def calculate_quarters(cents):
    return calculate_cents(cents, 25)

def calculate_dimes(cents):
    return calculate_cents(cents, 10)

def calculate_nickels(cents):
    return calculate_cents(cents, 5)

def calculate_pennies(cents):
    return calculate_cents(cents, 1)

def main():
    cents = get_dollars()
    cents = round(cents * 100)

    quarters = calculate_quarters(cents)
    cents = cents - quarters * 25

    dimes = calculate_dimes(cents)
    cents = cents - dimes * 10

    nickels = calculate_nickels(cents)
    cents = cents - nickels * 5

    pennies = calculate_pennies(cents)
    cents = cents - pennies * 1

    coins = quarters + dimes + nickels + pennies

    print(coins)





main()