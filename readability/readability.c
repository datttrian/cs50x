#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// Function prototypes
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Prompt the user for input and store it in the 'text' variable
    string text = get_string("Text: ");

    // Count the number of letters, words, and sentences in the input text
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    // Calculate the Coleman-Liau index directly in main
    float L = (float) letters / words * 100;
    float S = (float) sentences / words * 100;
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    // Determine and print the corresponding reading level based on the index
    if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }

    return 0;
}

// Count the number of letters in the input text
int count_letters(string text)
{
    int count = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        // Check if the character at position 'i' is alphabetic
        if (isalpha(text[i]))
        {
            count++;
        }
    }
    return count;
}

// Count the number of words in the input text
int count_words(string text)
{
    int count = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        // Check if the character at position 'i' is a whitespace character
        if (isspace(text[i]))
        {
            count++;
        }
    }
    return count + 1; // add 1 to account for the last word
}

// Count the number of sentences in the input text
int count_sentences(string text)
{
    int count = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        // Check for sentence-ending punctuation (., !, ?)
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count++;
        }
    }
    return count;
}
