#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int convert(string input);

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%i\n", convert(input));
}

int convert(string input)
{
    // Length of the input
    int len = strlen(input);

    // If input length = 1, return the integer value of that single number
    if (len == 1)
    {
        return input[0] - 48;
    }

    // Get the integer number for the last character
    int num = input[len - 1] - 48;

    // Move the string pointer to the last character to shorten it
    input[len - 1] = '\0';

    // Return the number and call the function recursively
    return num + 10 * convert(input);
}