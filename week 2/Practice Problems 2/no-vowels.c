// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>
string replace(string word);
int main(int argc, string argv[])
{

    // If the command-line argument equals 2, then we replace the vowels in the word.
    // If not, an error message is printed and 1 is returned
    if (argc == 2)
    {
        string replacedWord = replace(argv[1]);
        printf("%s\n", replacedWord);
    }
    else
    {
        printf("An error has occurred. No or too many command-line argument supplied.\n");
        return 1;
    }
}
// Function to replaces the vowels in a word with different numbers
string replace(string word)
{
    int l = strlen(word);
    for (int i = 0; i < l; i++)
    {
        // Checks if the current char is a vowel, and replaces it with a particular number
        switch (word[i])
        {
            case 'a':
                word[i] = '6';
                break;
            case 'e':
                word[i] = '3';
                break;
            case 'i':
                word[i] = '1';
                break;
            case 'o':
                word[i] = '0';
                break;
            default:
                word[i] = word[i];
                break;
        }
    }

    // Returns the modified word
    return word;
}