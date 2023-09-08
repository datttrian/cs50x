#include <cs50.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// Define macros for uppercase letters start, lowercase letters start, and total letter count.
#define UPPERCASE_LETTERS_START 'A'
#define LOWERCASE_LETTERS_START 'a'
#define LETTERS_COUNT 26

int main(int argc, string argv[])
{
    // Check if the program was called with the correct number of command-line arguments.
    if (argc != 2)
    {
        printf("Usage: %s key\n", argv[0]);
        return 1; // Exit the program with an error code.
    }

    // Store the key from the command line argument and find its length.
    string key = argv[1];
    int keyLength = strlen(key);

    // Check if the key has exactly 26 characters.
    if (keyLength != LETTERS_COUNT)
    {
        printf("Key must contain %d characters.\n", LETTERS_COUNT);
        return 1; // Exit the program with an error code.
    }

    // Create an array to keep track of used characters in the key.
    bool used[LETTERS_COUNT] = {false};

    // Loop through the key characters and perform checks.
    for (int i = 0; i < keyLength; i++)
    {
        // Check if the character is not alphabetic.
        if (!isalpha(key[i]))
        {
            printf("Key must contain only alphabetic characters.\n");
            return 1; // Exit the program with an error code.
        }

        // Convert the character to lowercase and calculate its index in the alphabet.
        int index = tolower(key[i]) - LOWERCASE_LETTERS_START;

        // Check if the character has already been used in the key.
        if (used[index])
        {
            printf("Key must contain each letter exactly once.\n");
            return 1; // Exit the program with an error code.
        }

        used[index] = true;
    }

    // Prompt for plaintext input.
    printf("plaintext: ");
    string plaintext = get_string("");

    // Encrypt and print ciphertext.
    printf("ciphertext: ");
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        char c = plaintext[i];
        if (isalpha(c))
        {
            int index = isupper(c) ? c - UPPERCASE_LETTERS_START : c - LOWERCASE_LETTERS_START;

            // Encrypt the character using the key and print the result.
            printf("%c", isupper(c) ? toupper(key[index]) : tolower(key[index]));
        }
        else
        {
            // If the character is not alphabetic, print it as is.
            printf("%c", c);
        }
    }
    printf("\n");

    return 0; // Exit the program with a success code.
}
