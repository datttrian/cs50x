#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    // TODO
    // Get the message from the user
    string message = get_string("Message: ");

    // Iterate through each character of the message
    for (int i = 0; i < strlen(message); i++)
    {
        char c = message[i];

        // Convert the character to binary and print it
        for (int j = BITS_IN_BYTE - 1; j >= 0; j--)
        {
            int bit = (c >> j) & 1; // extract the j-th bit of the character using bitwise operator
            print_bulb(bit);
        }

        // Print a newline after each byte
        printf("\n");
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
