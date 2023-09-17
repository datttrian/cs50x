#include <cs50.h>
#include <stdio.h>

int main()
{
    // Prompt the user to input a positive long number
    long cc_number;
    do
    {
        cc_number = get_long("Number: ");
    }
    while (cc_number < 0);

    // Initialize variables for calculations and tracking digits and sums
    int digit1 = 0, digit2 = 0, num_digits = 0, sum_of_double_odds = 0, sum_of_evens = 0;

    // While there are digits in the credit card number
    while (cc_number > 0)
    {
        // Extract the current digit and the previous digit
        digit2 = digit1;
        digit1 = cc_number % 10;

        // Determine if the current digit is at an even or odd position
        if (num_digits % 2 == 0)
        {
            // If it's at an even position, add it to sum_of_evens
            sum_of_evens += digit1;
        }
        else
        {
            // If it's at an odd position, double the digit and add its individual digits to sum_of_double_odds
            int multiple = 2 * digit1;
            sum_of_double_odds += (multiple / 10) + (multiple % 10);
        }

        // Move to the next digit and increment num_digits
        cc_number /= 10;
        num_digits++;
    }

    // Check if the sum of sum_of_evens and sum_of_double_odds is a multiple of 10
    bool is_valid = (sum_of_evens + sum_of_double_odds) % 10 == 0;

    // Extract the first two digits of the credit card number
    int first_two_digits = (digit1 * 10) + digit2;

    // Check for conditions to identify the credit card company
    if (digit1 == 4 && num_digits >= 13 && num_digits <= 16 && is_valid)
    {
        // If the first digit is 4, and the number of digits is between 13 and 16, and it's valid, print "VISA\n"
        printf("VISA\n");
    }
    else if (first_two_digits >= 51 && first_two_digits <= 55 && num_digits == 16 && is_valid)
    {
        // If the first two digits are between 51 and 55, and the number of digits is 16, and it's valid, print "MASTERCARD\n"
        printf("MASTERCARD\n");
    }
    else if ((first_two_digits == 34 || first_two_digits == 37) && num_digits == 15 && is_valid)
    {
        // If the first two digits are 34 or 37, and the number of digits is 15, and it's valid, print "AMEX\n"
        printf("AMEX\n");
    }
    else
    {
        // If none of the above conditions are met, print "INVALID\n"
        printf("INVALID\n");
    }
}
