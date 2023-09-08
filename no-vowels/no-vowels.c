// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Define character constants for vowels
#define VOWEL_A 54 // 'a' will be replaced with 54 ('6')
#define VOWEL_E 51 // 'e' will be replaced with 51 ('3')
#define VOWEL_I 49 // 'i' will be replaced with 49 ('1')
#define VOWEL_O 48 // 'o' will be replaced with 48 ('0')

string replace(string input_string);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./no-vowels word\n"); // print usage message if the number of arguments is not 2
        return 1;                            // return with an error code
    }
    printf("%s\n", replace(argv[1])); // print the result of calling the 'replace' function with the argument
}

string replace(string input_string)
{
    int length = strlen(input_string); // get the length of the input string

    for (int i = 0; i < length; i++) // iterate through each character in the input string
    {
        switch (input_string[i]) // check the current character
        {
            case 'a':
                input_string[i] = VOWEL_A;
                break;
            case 'e':
                input_string[i] = VOWEL_E;
                break;
            case 'i':
                input_string[i] = VOWEL_I;
                break;
            case 'o':
                input_string[i] = VOWEL_O;
                break;
        }
    }

    return input_string; // return the modified input string
}
