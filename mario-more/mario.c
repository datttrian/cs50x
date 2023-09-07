#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Positive Number: "); // prompt the user for a positive integer
    }
    while (n < 1 || n > 8); // keep asking until the input is between 1 and 8 (inclusive)

    // This loop is used to print the rows of the pyramid
    for (int i = 0; i < n; i++)
    {
        // Loop to print spaces and the first set of hashes
        for (int j = 0; j < n; j++)
        {
            if (j < n - i - 1)
            {
                printf(" "); // print a space
            }
            else
            {
                printf("#"); // print a hash
            }
        }

        // Print the gap between the two sets of hashes
        printf("  ");

        // Loop to print the second set of hashes
        for (int j = 0; j <= i; j++)
        {
            printf("#"); // print a hash
        }

        printf("\n"); // move to the next line after printing each row
    }
}
