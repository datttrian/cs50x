// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>

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
                input_string[i] = 54; // replace 'a' with ASCII code 54 ('6')
                break;
            case 'e':
                input_string[i] = 51; // replace 'e' with ASCII code 51 ('3')
                break;
            case 'i':
                input_string[i] = 49; // replace 'i' with ASCII code 49 ('1')
                break;
            case 'o':
                input_string[i] = 48; // replace 'o' with ASCII code 48 ('0')
                break;
        }
    }

    return input_string; // return the modified input string
}
