#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>

// Function prototypes
int count_letters(const char *text, int length);
int count_words(const char *text, int length);
int count_sentences(const char *text, int length);
int calculate_index(int letters, int words, int sentences);

int main(void)
{
    // Get user input as a string
    const char *text = get_string("Text: ");
    int length = strlen(text);

    // Count the number of letters, words, and sentences in the input
    int letters = count_letters(text, length);
    int words = count_words(text, length);
    int sentences = count_sentences(text, length);

    // Calculate the reading level using the Coleman-Liau index
    int index = calculate_index(letters, words, sentences);

    // Determine and print the corresponding reading level
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
int count_letters(const char *text, int length)
{
    int count = 0;
    for (int i = 0; i < length; i++)
    {
        // Check if the character is alphabetic
        if (isalpha(text[i]))
        {
            count++;
        }
    }
    return count;
}

// Count the number of words in the input text
int count_words(const char *text, int length)
{
    int count = 0;
    for (int i = 0; i < length; i++)
    {
        // Check if the character is a whitespace character
        if (isspace(text[i]))
        {
            count++;
        }
    }
    return count + 1; // add 1 to account for the last word
}

// Count the number of sentences in the input text
int count_sentences(const char *text, int length)
{
    int count = 0;
    for (int i = 0; i < length; i++)
    {
        // Check for sentence-ending punctuation (., !, ?)
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count++;
        }
    }
    return count;
}

// Calculate the Coleman-Liau index for the given parameters
int calculate_index(int letters, int words, int sentences)
{
    // Calculate the average number of letters per 100 words (L)
    float L = (float) letters / words * 100;

    // Calculate the average number of sentences per 100 words (S)
    float S = (float) sentences / words * 100;

    // Calculate the Coleman-Liau index and round to the nearest integer
    return round(0.0588 * L - 0.296 * S - 15.8);
}
