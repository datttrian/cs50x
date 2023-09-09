#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Positive Number: ");
    }
    while (n < 1 || n > 8); // keep asking until the input is between 1 and 8 (inclusive)

    // Outer loop for rows
    for (int i = 1; i <= n; i++)
    {
        // Inner loop for dots
        for (int j = 1; j <= n - i; j++)
        {
            printf(" ");
        }

        // Inner loop for hashes
        for (int k = 1; k <= i; k++)
        {
            printf("#");
        }

        // Move to the next row
        printf("\n");
    }

    return 0;
}
