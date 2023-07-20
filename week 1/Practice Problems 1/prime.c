#include <cs50.h>
#include <stdio.h>

bool prime(int number);

// Prints all the prime numbers between two numbers
int main(void)
{
    // Ask for starting number
    int min;
    do
    {
        min = get_int("Minimum: ");
    } while (min < 1);

    // Ask for the end number
    int max;
    do
    {
        max = get_int("Maximum: ");
    } while (min >= max);

    // Checks if each number between the min and max is a prime number. Prints the prime numbers.
    for (int i = min; i <= max; i++)
    {
        if (prime(i))
        {
            printf("%i\n", i);
        }
    }
}

bool prime(int number)
{
    if (number < 2)
    {
        return false;
    }
    else
    {
        for (int j = 2; j < number - 1; j++)
        {
            if (number % j == 0)
            {
                return false;
            }
        }
        return true;
    }
}
