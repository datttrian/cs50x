// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <stdio.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    // Initialize boolean variables to false
    bool hasUpperCase = false;
    bool hasLowerCase = false;
    bool hasNumber = false;
    bool hasSymbol = false;

    // Iterate through the password
    for (int i = 0, n = strlen(password); i < n; i++)
    {
        char c = password[i];

        // Check for uppercase letters
        if (isupper(c))
        {
            hasUpperCase = true;
        }
        // Check for lowercase letters
        else if (islower(c))
        {
            hasLowerCase = true;
        }
        // Check for numbers
        else if (isdigit(c))
        {
            hasNumber = true;
        }
        // Check for symbols (printable characters that are not letters or numbers)
        else if (!isalnum(c))
        {
            hasSymbol = true;
        }
    }

    // Check if all criteria are met
    return hasUpperCase && hasLowerCase && hasNumber && hasSymbol;
}
