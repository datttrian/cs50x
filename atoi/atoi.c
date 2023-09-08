#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int convert(string input);

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%i\n", convert(input));
}

int convert(string input)
{
    // TODO
    // Base case: If the string has only one character, convert and return it
    if (strlen(input) == 1)
    {
        return input[0] - '0'; // Convert char to int
    }
    else
    {
        // Recursive case: Convert the last character and call convert on the rest of the string
        int lastDigit = input[strlen(input) - 1] - '0'; // Convert last char to int
        string shortenedInput = input;
        shortenedInput[strlen(input) - 1] = '\0';     // Shorten the string by removing the last character
        int remainingValue = convert(shortenedInput); // Recursive call
        return remainingValue * 10 + lastDigit;       // Combine the results
    }
}