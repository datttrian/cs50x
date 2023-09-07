#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Positive Number: ");
    }
    while (n < 1 || n > 8);

    // For each new row
    for (int i = 1; i <= n; i++)
    {
        // For each row's bricks
        for (int j = 1; j <= n; j++)
        {
            if (j <= n - i)
            {
                // Print blank spaces
                printf(" ");
            }
            else
            {
                // Print the brick
                printf("#");
            }
        }

        printf("  ");

        for (int k = n; k >= 1; k--)
        {
            if (k <= n - i)
            {
                // Skip for no character at all
            }
            else
            {
                // Print the bricks
                printf("#");
            }
        }

        // Go to the next line
        printf("\n");
    }
}
