#include <cs50.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define UPPERCASE_LETTERS_START 'A'
#define LOWERCASE_LETTERS_START 'a'
#define LETTERS_COUNT 26

int main(int argc, string argv[])
{
    // If the argument count is not 2
    if (argc != 2)
    {
        // Print an error message ("Usage: program_name key")
        printf("Usage: %s key\n", argv[0]);

        // Exit with an error code (1)
        return 1;
    }

    // Store the second command-line argument and its length as a string key and an integer keyLength
    string key = argv[1];
    int keyLength = strlen(key);

    // If keyLength is not 26
    if (keyLength != LETTERS_COUNT)
    {
        // Print an error message ("Key must contain 26 characters")
        printf("Key must contain %d characters.\n", LETTERS_COUNT);

        // Exit with an error code (1)
        return 1;
    }

    // Create an array of false values to keep track of used characters in the key
    bool used[LETTERS_COUNT] = {false};

    // Loop through the key characters and perform checks
    for (int i = 0; i < keyLength; i++)
    {
        // If the character is not alphabetic
        if (!isalpha(key[i]))
        {
            // Print an error message ("Key must contain only alphabetic characters.\n")
            printf("Key must contain only alphabetic characters.\n");

            // Exit with an error code (1)
            return 1;
        }

        // Calculate the character position in the alphabet and store it to an integer index
        int index = tolower(key[i]) - LOWERCASE_LETTERS_START;

        // If the element in the used array at the specified index is true
        if (used[index])
        {
            // Print an error message ("Key must contain each letter exactly once")
            printf("Key must contain each letter exactly once.\n");

            // Exit with an error code (1)
            return 1;
        }

        // Mark the element in the used array at the specified index as true
        used[index] = true;
    }

    // Display "plaintext: " to prompt the user input a string and store it in plaintext
    string plaintext = get_string("plaintext: ");

    // Display "ciphertext: "
    printf("ciphertext: ");

    // Loop through each character in the plaintext
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        char c = plaintext[i];

        // If the character is alphabetic
        if (isalpha(c))
        {
            // Calculate its index in the alphabet
            int index = isupper(c) ? c - UPPERCASE_LETTERS_START : c - LOWERCASE_LETTERS_START;

            // Replace the character with the corresponding character from the key while maintaining the case
            char replacementChar = isupper(c) ? toupper(key[index]) : tolower(key[index]);

            // Print the character
            printf("%c", replacementChar);
        }
        else
        {
            // Print the character unchanged
            printf("%c", c);
        }
    }
    printf("\n");

    return 0;
}
