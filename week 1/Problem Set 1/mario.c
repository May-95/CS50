#include <cs50.h>
#include <stdio.h>

void printHashes(int space, int i, int halfway);

int main(void)
{
    // Ask user for the height. Cannot be under than 1.
    int height = 0;
    do
    {
        height = get_int("Height: ");
    } while (height < 1 || height > 8);

    // Loops through until the height number is achieved. Using printHashes function to print that line's hashes and spaces.
    int space = height;
    for (int i = 0; i < height; i++)
    {
        int stars = (i + 1) * 2;
        int halfway = stars / 2;
        printHashes(space, stars, halfway);
        if (i != height + 1)
        {
            printf("\n");
        }
        space--;
    }
}

// Adds the hashes and spaces for each line
void printHashes(int space, int i, int halfway)
{
    // Adds the appropriate number of spaces for that line.
    for (int j = space; j > 1; j--)
    {
        printf(" ");
    }

    // Adds the hashes for the line. Two spaces are put in the middle of that line's number of hashes.
    for (int k = 0; k < i + 1; k++)
    {
        if (k == halfway)
        {
            printf("  ");
        }
        else
        {
            printf("#");
        }
    }
}