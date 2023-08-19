// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <stdio.h>
#include <string.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// Check if password is valid. Must have one upper and one lower character, one symbol and one number.
bool valid(string password)
{
    bool lower = false;
    bool upper = false;
    bool number = false;
    bool symbol = false;

    // Loops through the password to check each character and see if it meets the requirements
    for (int i = 0, l = strlen(password); i < l; i++)
    {
        if (password[i] >= 97 && password[i] <= 122)
        {
            lower = true;
        }
        else if (password[i] >= 65 && password[i] <= 90)
        {
            upper = true;
        }
        else if (password[i] >= 48 && password[i] <= 57)
        {
            number = true;
        }
        else if ((password[i] >= 33 && password[i] <= 47) || (password[i] >= 58 && password[i] <= 64) ||
                 (password[i] >= 91 && password[i] <= 96) || (password[i] >= 123 && password[i] <= 126))
        {
            symbol = true;
        }
    }

    // Returns true if one symbol, one number, one upper and one lower character are present in the password
    if (lower && upper && number && symbol)
    {
        return true;
    }
    return false;
}
