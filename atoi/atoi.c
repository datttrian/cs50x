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
    // Base case: If the string is empty or has only one character (null terminator),
    // return the integer value of that character.
    if (str[0] == '\0' || str[1] == '\0') {
        return str[0] - '0';
    }

    // Recursively calculate the integer value of the substring without the last character.
    int smallerValue = convert(str + 1);

    // Calculate the integer value of the current character and combine it with the
    // value from the smaller substring.
    int currentValue = str[0] - '0';
    int result = currentValue * (int)pow(10, strlen(str) - 1) + smallerValue;

    return result;
}