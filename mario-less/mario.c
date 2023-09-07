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

int main()
{
    int height, width;

    // This loop ensures that the user inputs a valid 'height' value between 0 and 23.
    do
    {
        height = get_int("Height: "); // Prompt user for pyramid height.
        width = height; // Set 'width' equal to 'height' as each row's width equals the height.
    }
    while (height < 0 || height > 23); // Repeat the loop if height is not within the valid range.

    // This loop iterates through each row of the pyramid.
    for (int i = 1; i <= height; i++)
    {
        int num_hashes = i; // Number of '#' symbols in the current row.
        int num_spaces = width - num_hashes; // Number of spaces in the current row.

        repeat(' ', num_spaces); // Print the required number of spaces.
        repeat('#', num_hashes); // Print the required number of '#' symbols.

        printf("  "); // Print two spaces in between the pyramid halves.

        repeat('#', num_hashes); // Print the required number of '#' symbols again.

        printf("\n"); // Move to the next line for the next row.
    }

    return 0; // Indicates successful program execution.
}
