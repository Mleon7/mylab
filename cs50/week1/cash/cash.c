#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}

int get_cents(void)
{
    int cents;
    do
    {
        cents = get_int("Change owed: ");
    } while (cents <= 0);
    // TODO
    return cents;
}

int calculate_quarters(int cents)
{
    // TODO
    int cnt = 1; // 需返回硬币数量
    int temp = 25; // 
    while (temp <= cents)
    {
        cnt++;
        temp = 25 * cnt;
    }
    return cnt - 1;
}

int calculate_dimes(int cents)
{
    // TODO
    int cnt = 1; // 需返回硬币数量
    int temp = 10; // 
    while (temp <= cents)
    {
        cnt++;
        temp = 10 * cnt;
    }
    return cnt - 1;
}

int calculate_nickels(int cents)
{
    // TODO
    int cnt = 1; // 需返回硬币数量
    int temp = 5; // 
    while (temp <= cents)
    {
        cnt++;
        temp = 5 * cnt;
    }
    return cnt - 1;
}

int calculate_pennies(int cents)
{
    // TODO
    int cnt = 1; // 需返回硬币数量
    int temp = 1; // 
    while (temp <= cents)
    {
        cnt++;
        temp = 1 * cnt;
    }
    return cnt - 1;
}
