#include <cs50.h>
#include <stdio.h>

void repeat(char c, int times)
{
    while (--times >= 0)
    {
        printf("%c", c);
    }
}

int main(void)
{
    int n;
    do
    {
        n = get_int("Positive Number: "); // prompt the user for a positive integer
    }
    while (n < 1 || n > 8); // keep asking until the input is between 1 and 8 (inclusive)

    // This loop is used to print the rows of the pyramid
    for (int i = 1; i <= n; i++)
    {
        // Print spaces and the first set of hashes
        repeat(' ', n - i);
        repeat('#', i);

        // Print the gap between the two sets of hashes
        printf("  ");

        // Print the second set of hashes
        repeat('#', i);

        // Move to the next line after printing each row
        printf("\n");
    }
}
