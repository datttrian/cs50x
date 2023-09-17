#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Display "What's your name? " to prompt the user to input their name using cs50 function
    string name = get_string("What's your name? ");

    // Print a greeting message including the user's inputted name
    printf("hello, %s\n", name);
}
