#include <cs50.h>
#include <stdio.h>

// Determine how long it takes for a population to reach a particular size.
// With 1/3 being born each year and 1/4 dying each year.
int main(void)
{
    // Prompt for start size
    int start = 0;

    do
    {
        start = get_int("Start size: ");
    }
    while (start < 9);

    int end = 0;
    // Prompt for end size
    do
    {
        end = get_int("End size: ");
    }
    while (start > end);

    // Calculate number of years until we reach threshold
    int years = 0;

    while (start < end)
    {
        int born = start / 3;
        int died = start / 4;
        start += born - died;
        years++;
    };

    // Print number of years
    printf("Years: %i\n", years);
}