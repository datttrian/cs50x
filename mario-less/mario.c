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

    // For each row from '1' to 'n'
    for (int row = 1; row <= n; i++)
    {
        // Print 'n - row' spaces
        for (int i = 1; i <= n - i; i++)
        {
            printf(" ");
        }

        // Print 'row' hash symbols ('#') for the pyramid
        for (int j = 1; j <= i; j++)
        {
            printf("#");
        }

        // Move to the next line for the next row
        printf("\n");
    }

    return 0;
}
