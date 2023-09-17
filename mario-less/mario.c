#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Display "Positive Number: " to prompt the user to input a positive integer from 1 to 8 and store it in n
    int n;
    do
    {
        n = get_int("Positive Number: ");
    }
    while (n < 1 || n > 8);

    // Iterate through each row
    for (int row = 0; row < n; row++)
    {
        // Print 'n - row' spaces
        for (int i = 0; i < n - row - 1; i++)
        {
            printf(" ");
        }

        // Print 'row' hash symbols ('#')
        for (int j = 0; j < row + 1; j++)
        {
            printf("#");
        }

        // Move to the next line
        printf("\n");
    }

    return 0;
}
