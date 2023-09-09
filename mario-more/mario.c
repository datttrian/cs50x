#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Display "Positive Number: " to prompt the user input a positive integer between 1 and 8 and store it in n
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);

    // For each row from 1 to 'n'
    for (int i = 1; i <= n; i++)
    {
        // Inner loop for n - i spaces before the hashes
        for (int j = 1; j <= n - i; j++)
        {
            printf(" ");
        }

        // Inner loop for i left hashes
        for (int k = 1; k <= i; k++)
        {
            printf("#");
        }

        // Gap between pyramids
        printf("  ");

        // Inner loop for i right hashes
        for (int l = 1; l <= i; l++)
        {
            printf("#");
        }

        // Move to the next row
        printf("\n");
    }

    return 0;
}
