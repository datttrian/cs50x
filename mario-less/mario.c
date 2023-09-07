#include <cs50.h>
#include <stdio.h>

// This function repeats a character 'c' 'times' number of times and prints them.
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
        // Print spaces before the hashes
        repeat(' ', n - i);

        // Print the hashes
        repeat('#', i);

        printf("\n"); // move to the next line after printing each row
    }
}
