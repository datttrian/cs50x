// Practice writing a function to find a max value

#include <cs50.h>
#include <stdio.h>

int max(int array[], int n);

int main(void)
{
    int n;
    do
    {
        n = get_int("Number of elements: ");
    }
    while (n < 1);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = get_int("Element %i: ", i);
    }

    printf("The max value is %i.\n", max(arr, n));
}

// TODO: return the max value
int max(int array[], int n)
{
    // Initialize the max value to the first element of the array
    int max_value = array[0];

    // Iterate through the array to find the maximum value
    for (int i = 1; i < n; i++)
    {
        // If the current element is greater than the current max_value, update max_value
        if (array[i] > max_value)
        {
            max_value = array[i];
        }
    }

    // Return the maximum value found
    return max_value;
}
