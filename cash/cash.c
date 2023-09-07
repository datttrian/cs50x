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
    // TODO
    int cents;
    do
    {
        cents = get_int("Change owed: "); // prompt the user for the change owed
    }
    while (cents < 0); // keep asking until until a non-negative value is entered
    return cents;
}

int calculate_quarters(int cents)
{
    // TODO
    int quarters = cents / 25; // calculate quarters by dividing cents by 25
    return quarters;
}

int calculate_dimes(int cents)
{
    // TODO
    int dimes = (cents % 25) / 10; // calculate dimes using the remainder divided by 10
    return dimes;
}

int calculate_nickels(int cents)
{
    // TODO
    int nickels = (cents % 25 % 10) / 5; // calculate nickels using the remainder divided by 5
    return nickels;
}

int calculate_pennies(int cents)
{
    // TODO
    int pennies = cents % 5; // equivalent to ((cents % 25) % 10) % 5;
    return pennies;
}
