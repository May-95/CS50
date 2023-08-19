#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

float calc_hours(int hours[], int weeks, char output);

int main(void)
{
    // Asks user the number of weeks they have taken
    int weeks = get_int("Number of weeks taking CS50: ");
    int hours[weeks];

    // The number of hours for each week
    for (int i = 0; i < weeks; i++)
    {
        hours[i] = get_int("Week %i HW Hours: ", i);
    }

    // Asks if they want the total number of hours or if they want the average hours per week
    char output;
    do
    {
        output = toupper(get_char("Enter T for total hours, A for average hours per week: "));
    }
    while (output != 'T' && output != 'A');

    // Prints the results to the user
    printf("%.1f hours\n", calc_hours(hours, weeks, output));
}

// Calculates the total hours or the average depending on user's input
float calc_hours(int hours[], int weeks, char output)
{
    // Calculates the total of hours
    int total = 0;
    for (int i = 0; i < weeks; i++)
    {
        total += hours[i];
    }

    // Returns the total of hours if output is T and the average hours per week if output is A
    if (output == 'T')
    {
        return total;
    }
    else
    {
        return total / (float) weeks;
    }
}