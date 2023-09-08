#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    // Make sure the program was run with just one command-line argument
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Make sure every character in argv[1] is a digit
    string key_str = argv[1];
    for (int i = 0; key_str[i] != '\0'; i++)
    {
        if (!isdigit(key_str[i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    // Convert argv[1] from a `string` to an `int`
    int key = atoi(key_str) % 26;;

    // Prompt the user for plaintext
    string plaintext = get_string("plaintext: ");

    // For each character in the plaintext:
    printf("ciphertext: ");
    for (int i = 0; plaintext[i] != '\0'; i++)
    {
        // Rotate the character if it's a letter
        char rotated_char = plaintext[i];
        if (isalpha(plaintext[i]))
        {
            char base = islower(plaintext[i]) ? 'a' : 'A';
            rotated_char = (rotated_char - base + key) % 26 + base;
        }
        printf("%c", rotated_char);
    }
    printf("\n");

    return 0;
}
