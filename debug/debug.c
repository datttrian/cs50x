// Become familiar wih C syntax
// Learn to debug buggy code

#include <cs50.h>
#include <stdio.h> // TODO: Include the standard I/O library

int main(void)
{
    // TODO: Declare variables to store name and location
    string name;
    string location;

    // Ask for your name and where live
    name = get_string("What is your name? ");     // TODO: debug
    location = get_string("Where do you live? "); // TODO: debug

    // Say hello
    printf("Hello, %s, from %s!\n", name, location); // TODO: debug
}
