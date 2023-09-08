#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

#define ZERO '0' // Define constant ZERO for '0' character

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
        return input[0] - ZERO; // convert char to int
    }
    else
    {
        // Recursive case: Convert the last character and call convert on the rest of the string
        int lastDigit = input[strlen(input) - 1] - ZERO; // convert last char to int
        string shortenedInput = input;
        shortenedInput[strlen(input) - 1] = '\0';     // shorten the string by removing the last character
        int remainingValue = convert(shortenedInput); // recursive call
        return remainingValue * 10 + lastDigit;       // combine the results
    }
}
