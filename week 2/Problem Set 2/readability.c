#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int reading_level(int letter, int word, int sentence);

int main(void)
{
    string input = get_string("Text: ");
    int grade = reading_level(count_letters(input), count_words(input), count_sentences(input));
    if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

// Count the number of letters in the text
int count_letters(string text)
{
    int count = 0;
    for (int i = 0, l = strlen(text); i < l; i++)
    {
        char current = toupper(text[i]);
        if (current >= 65 && current <= 90)
        {
            count++;
        }
    }
    return count;
}

// Count the number of words in the text
int count_words(string text)
{
    int count = 1;
    for (int i = 0, l = strlen(text); i < l; i++)
    {
        char current = toupper(text[i]);
        if (current == 32)
        {
            count++;
        }
    }
    return count;
}

// Count the number of sentences in the text
int count_sentences(string text)
{
    int count = 0;
    for (int i = 0, l = strlen(text); i < l; i++)
    {
        char current = toupper(text[i]);
        if (current == 33 || current == 46 || current == 63)
        {
            count++;
        }
    }
    return count;
}

// Calculate the reading grade
int reading_level(int letter, int word, int sentence)
{
    float letters_per_100 = (float) letter / (float) word * 100;
    float sentences_per_100 = (float) sentence / (float) word * 100;
    float index = 0.0588 * letters_per_100 - 0.296 * sentences_per_100 - 15.8;
    return round(index);
}