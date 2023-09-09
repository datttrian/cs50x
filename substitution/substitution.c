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
    // Check if the program was called with 2 command-line arguments
    if (argc != 2)
    {
        // Print an error message ("Usage: program_name key")
        printf("Usage: %s key\n", argv[0]);

        // Exit with an error code (1)
        return 1;
    }

    // Store the second command-line argument and its length as a string and an integer
    string key = argv[1];
    int keyLength = strlen(key);

    // Check if the key has exactly 26 characters
    if (keyLength != LETTERS_COUNT)
    {
        printf("Key must contain %d characters.\n", LETTERS_COUNT);
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
        int index = tolower(key[i]) - UPPERCASE_LETTERS_START;

        // Check if the character has already been used in the key
        if (used[index])
        {
            printf("Key must contain each letter exactly once.\n");
            return 1;
        }

        used[index] = true;
    }

    // Display "plaintext: " to prompt the user input a string and store it in plaintext
    string plaintext = get_string("plaintext: ");

    // Initialize an empty string (ciphertext) to store the encrypted text
    printf("ciphertext: ");
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        char c = plaintext[i];
        if (isalpha(c))
        {
            int index = isupper(c) ? c - UPPERCASE_LETTERS_START : c - LOWERCASE_LETTERS_START;

            // Encrypt the character using the key and print the result
            printf("%c", isupper(c) ? toupper(key[index]) : tolower(key[index]));
        }
        else
        {
            // If the character is not alphabetic, print it as is
            printf("%c", c);
        }
    }
    printf("\n");

    return 0;
}
