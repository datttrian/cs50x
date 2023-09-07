#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string name = get_string("What's your name? "); // prompt the user to input their name using cs50 function.
    printf("hello, %s\n", name); // print a greeting message including the user's inputted name.
}
