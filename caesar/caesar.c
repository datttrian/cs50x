#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define macros for uppercase letters start, lowercase letters start, and total letter count.
#define UPPERCASE_LETTERS_START 'A'
#define LOWERCASE_LETTERS_START 'a'
#define LETTERS_COUNT 26

int main(int argc, string argv[])
{
    // Check if the program was called with 2 command-line arguments
    if (argc != 2)
    {
        // If the argument count is not 2, print an error message
        printf("Usage: %s key\n", argv[0]);

        // Exit with an error code 1
        return 1;
    }

    // Store the second command-line argument as a string
    string key_str = argv[1];

    // Loop through each character in the argument:
    for (int i = 0; i < strlen(key_str); i++)
    {
        // If it's not a digit
        if (!isdigit(key_str[i]))
        {
            // Print an error message ("Usage: program_name key")
            printf("Usage: ./caesar key\n");

            // Exit with an error code 1
            return 1;
        }
    }

    // Convert the string argument to integer
    int key = atoi(key_str);

    // Prompt the user to enter plaintext
    string plaintext = get_string("plaintext: ");

    // Display "ciphertext: "
    printf("ciphertext: ");
    for (int i = 0; plaintext[i] != '\0'; i++)
    {
        // Initialize variables rotated_char to store the inputted plaintext
        char rotated_char = plaintext[i];

        // Loop through each character in the plaintext,
        if (isalpha(plaintext[i]))
        {
            char base = isupper(plaintext[i]) ? UPPERCASE_LETTERS_START : LOWERCASE_LETTERS_START;
            rotated_char = (rotated_char - base + key) % LETTERS_COUNT + base;
        }
        printf("%c", rotated_char);
    }
    printf("\n");

    return 0;
}
