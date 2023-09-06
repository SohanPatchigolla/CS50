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

// Gets input from the customer.
int get_cents(void)
{
    int cents;
    do
    {
        cents = get_int("How many cents do we owe?: ");
    }
    while (cents < 1);
    return cents;
}

// Counts the number of quarters used.
int calculate_quarters(int cents)
{
    int quarter = 25;
    int q_count = 0;
    while (cents >= 25)
    {
        cents = cents - quarter;
        q_count++;
    }
    return q_count;
}

// Counts the number of dimes used.
int calculate_dimes(int cents)
{
    int dime = 10;
    int d_count = 0;
    while (cents < 25 && cents >= 10)
    {
        cents = cents - dime;
        d_count++;
    }
    return d_count;
}

// Counts the number of nickels used.
int calculate_nickels(int cents)
{
    int nickel = 5;
    int n_count = 0;
    while (cents < 10 && cents >= 5 )
    {
        cents = cents - nickel;
        n_count++;
    }
    return n_count;
}

// Counts the number of pennies used.
int calculate_pennies(int cents)
{
    int penny = 1;
    int p_count = 0;
    while (cents < 5 && cents >= 1)
    {
        cents = cents - penny;
        p_count++;
    }
    return p_count;
}
