#include <stdio.h>
#include <cs50.h>

// Prints a greeting with the user's name.
int main(void)
{
    // Ask user for name.
    string name = get_string("What is your name? ");

    // Print hello, and the user's inputted name.
    printf("hello, %s\n", name);
}