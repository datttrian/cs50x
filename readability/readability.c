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
    // Prompt the user to input a text and store it in the 'text' variable
    string text = get_string("Text: ");

    // Count the number of letters, words, and sentences in the input text
    int letters = count_letters(text); // call count_letters(text) and store the result in 'letters_count'
    int words = count_words(text); // call count_words(text) and store the result in 'words_count'
    int sentences = count_sentences(text); // call count_sentences(text) and store the result in 'sentences_count'

    // Calculate the Coleman-Liau index (CLI)
    float L = (float) letters / words * 100; // calculate the average number of letters per 100 words (L)
    float S = (float) sentences / words * 100; // calculate the average number of sentences per 100 words (S)
    int index = round(0.0588 * L - 0.296 * S - 15.8); // Calculate the index using the formula: index = 0.0588 * L - 0.296 * S - 15.8

    // Determine the reading level based on the CLI:
    if (index > 16)
    {
        // If the index is greater than 16, print "Grade 16+\n"
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        // If the index is less than 1, print "Before Grade 1\n"
        printf("Before Grade 1\n");
    }
    else
    {
        // Otherwise, print "Grade X\n" where X is the integer value of the index
        printf("Grade %i\n", index);
    }

    return 0;
}

// Count the number of letters in the input text
int count_letters(string text)
{
    // Initialize a counter 'count' to 0
    int count = 0;

    // Loop through each character in 'text'
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        // If it's alphabetic, increment 'count' by '1'
        if (isalpha(text[i]))
        {
            count++;
        }
    }

    // Return 'count'
    return count;
}

// Count the number of words in the input text
int count_words(string text)
{
    // Initialize a counter 'count' to '1' to account for the first word
    int count = 1;

    // Loop through each character in 'text'
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        // If it's a whitespace, increment 'count' by '1'
        if (isspace(text[i]))
        {
            count++;
        }
    }

    // Return 'count'
    return count;
}

// Count the number of sentences in the input text
int count_sentences(string text)
{
    // Initialize a counter 'count' to 0
    int count = 0;

    // Loop through each character in 'text'
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        // If it's a punctuation character (., !, ?), increment 'count' by '1'
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count++;
        }
    }

    // Return 'count'
    return count;
}
