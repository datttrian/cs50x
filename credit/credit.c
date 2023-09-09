#include <cs50.h>
#include <stdio.h>

int main()
{
    // Display "Number: " to prompt the user input a long integer between 1 and 8 and store it in n
    do
    {
        card_number = get_long("Number: ");
    }
    while (card_number < 0);

    // Initialize variables for various calculations and tracking digits and sums
    int digit1 = 0, digit2 = 0, num_digits = 0, sum_of_double_odds = 0, sum_of_evens = 0;

    // Process each digit in the credit card number until there are no more digits
    while (cc_number > 0)
    {
        // Store the current digit and the previous digit
        digit2 = digit1;
        digit1 = cc_number % 10;

        // Determine whether the current digit is at an even or odd position
        if (num_digits % 2 == 0)
        {
            // If the digit is at an even position, add it to the sum of evens
            sum_of_evens += digit1;
        }
        else
        {
            // If the digit is at an odd position, double it and add its digits to the sum of double odds
            int multiple = 2 * digit1;
            sum_of_double_odds += (multiple / 10) + (multiple % 10);
        }

        // Move to the next digit in the credit card number and increment the digit count
        cc_number /= 10;
        num_digits++;
    }

    // Check if the sum of all calculated sums is a multiple of 10 (i.e., if it's a valid credit card number)
    bool is_valid = (sum_of_evens + sum_of_double_odds) % 10 == 0;

    // Extract the first two digits of the credit card number
    int first_two_digits = (digit1 * 10) + digit2;

    // Check for various credit card company and length conditions and print the result
    if (digit1 == 4 && num_digits >= 13 && num_digits <= 16 && is_valid)
    {
        printf("VISA\n");
    }
    else if (first_two_digits >= 51 && first_two_digits <= 55 && num_digits == 16 && is_valid)
    {
        printf("MASTERCARD\n");
    }
    else if ((first_two_digits == 34 || first_two_digits == 37) && num_digits == 15 && is_valid)
    {
        printf("AMEX\n");
    }
    else
    {
        // If none of the conditions are met, the card is invalid
        printf("INVALID\n");
    }
}
