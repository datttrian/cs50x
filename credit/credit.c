#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt the user to enter a credit card number as a long long integer.
    long long cc_number = get_long_long("Number: ");

    int num_digits = 0;
    int sum_of_double_odds = 0;
    int sum_of_evens = 0;

    while (cc_number > 0)
    {
        // Extract the last digit.
        int digit = cc_number % 10;
        cc_number /= 10;

        // Keep track of the number of digits.
        num_digits++;

        if (num_digits % 2 == 0)
        {
            // If the digit is at an even position, add it directly to the sum of evens.
            sum_of_evens += digit;
        }
        else
        {
            // If the digit is at an odd position, double it and add its digits to the sum of double odds.
            int multiple = 2 * digit;
            sum_of_double_odds += (multiple / 10) + (multiple % 10);
        }
    }

    // Check if the sum of all calculated sums is a multiple of 10 (i.e., if it's a valid credit card number).
    bool is_valid = (sum_of_evens + sum_of_double_odds) % 10 == 0;

    // Determine the first two digits of the credit card number.
    int first_two_digits = cc_number; // The remaining cc_number should have the first two digits.

    // Check for various credit card company and length conditions and print the result.
    if (is_valid)
    {
        if ((num_digits == 13 || num_digits == 16) && first_two_digits / 10 == 4)
        {
            printf("VISA\n");
        }
        else if (num_digits == 16 && first_two_digits >= 51 && first_two_digits <= 55)
        {
            printf("MASTERCARD\n");
        }
        else if (num_digits == 15 && (first_two_digits == 34 || first_two_digits == 37))
        {
            printf("AMEX\n");
        }
        else
        {
            // If none of the conditions are met, the card is invalid.
            printf("INVALID\n");
        }
    }
    else
    {
        // If the card is not valid, print "INVALID".
        printf("INVALID\n");
    }
}