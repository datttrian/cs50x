#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Display "Height: " to prompt the user to input a positive integer between 1 and 8 and store it in n
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);

    // For each row from '1' to 'n'
    for (int row = 1; row <= n; row++)
    {
        // Print 'n - row' spaces
        for (int i = 1; i <= n - row; i++)
        {
            printf(" ");
        }

        // Print 'row' hash symbols ('#') for the left half of the pyramid
        for (int j = 1; j <= row; j++)
        {
            printf("#");
        }

        // Print 'two' spaces (" ") for the gap between the two pyramids
        printf("  ");

        // Print 'row' hash symbols ('#') for the right half of the pyramid
        for (int k = 1; k <= row; k++)
        {
            printf("#");
        }

        // Move to the next line for the next row
        printf("\n");
    }

    return 0;
}
