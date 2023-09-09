#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Display "Positive Number: " to prompt the user input a positive integer between 1 and 8 and store it in n
    int n;
    do
    {
        n = get_int("Positive Number: ");
    }
    while (n < 1 || n > 8);

    // For each row from 1 to 'n'
    for (int i = 1; i <= n; i++)
    {
        // Print spaces equal to 'n - the current row number'
        for (int j = 1; j <= n - i; j++)
        {
            printf(" ");
        }

        // Print 'the current row number' hash symbols ('#') for the pyramid
        for (int k = 1; k <= i; k++)
        {
            printf("#");
        }

        // Move to the next line for the next row
        printf("\n");
    }

    return 0;
}
