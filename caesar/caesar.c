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
    // Check if the program was called with the correct number of command-line arguments.
    if (argc != 2)
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }

    // Make sure every character in argv[1] is a digit
    string key_str = argv[1];
    for (int i = 0; i < strlen(key_str); i++)
    {
        if (!isdigit(key_str[i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    // Convert argv[1] from a `string` to an `int`
    int key = atoi(key_str);

    // Prompt the user for plaintext
    string plaintext = get_string("plaintext: ");

    // Encrypt and print ciphertext.
    printf("ciphertext: ");
    for (int i = 0; plaintext[i] != '\0'; i++)
    {
        // Rotate the character if it's a letter
        char rotated_char = plaintext[i];
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
