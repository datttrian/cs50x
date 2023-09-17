#include <cs50.h>
#include <stdio.h>

bool prime(int number);

int main(void)
{
    int min;
    do
    {
        min = get_int("Minimum: ");
    }
    while (min < 1);

    int max;
    do
    {
        max = get_int("Maximum: ");
    } 
    while (min >= max);
    
    for (int i = min; i <= max; i++)
    {
        if (prime(i))
        {
            printf("%i\n", i);
        }
    }
}

bool prime(int number)
{
    // TODO
    // Numbers less than or equal to 1 are not prime
    if (number <= 1)
    {
        return false;
    }

    // Two is a prime number
    if (number == 2)
    {
        return true;
    }

    // Even numbers greater than 2 are not prime
    if (number % 2 == 0)
    {
        return false;
    }

    // Numbers divisible by any odd number up to the square root are not prime
    for (int i = 3; i * i <= number; i += 2)
    {
        if (number % i == 0)
        {
            return false;
        }
    }

    // Other numbers are prime
    return true;
}
