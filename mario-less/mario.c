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
        // This loop is used to print spaces before the hashes
        for (int j = 0; j < n - i - 1; j++)
        {
            printf(" "); // print a space
        }

        // This loop is used to print the hashes
        for (int j = 0; j <= i; j++)
        {
            printf("#"); // print a hash
        }

        printf("\n"); // move to the next line after printing each row
    }
}
