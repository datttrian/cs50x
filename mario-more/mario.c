#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Positive Number: ");
    }
    while (n < 1 || n > 8);

    for (int i = 1; i <= n; i++)
    {

        for (int j = 1; j <= n; j++)
        {
            if (j <= n - i)
            {

                printf(" ");
            }
            else
            {

                printf("#");
            }
        }

        printf("  ");

        for (int k = n; k >= 1; k--)
        {
            if (k <= n - i)
            {
            }
            else
            {

                printf("#");
            }
        }

        printf("\n");
    }
}
