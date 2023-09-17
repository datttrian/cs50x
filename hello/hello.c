#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt the user to input their name
    string name = get_string("What's your name? ");

    // Print a greeting message including the user's inputted name
    printf("hello, %s\n", name);
}
