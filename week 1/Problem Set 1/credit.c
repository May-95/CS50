#include <cs50.h>
#include <stdio.h>
#include <string.h>

int calculate(int num, string card);
int main(void)
{
    // Get card number. Calculate the length of the number.
    string card = get_string("Number: ");
    int num = strlen(card);
    string response = "INVALID\n";

    // If card number length is 16 or 13, then it is either a VISA or a MASTERCARD. If it is 15, it is an AMEX.
    if (num == 16 || num == 13)
    {
        int firstNum = card[0] - '0';
        int secondNum = card[1] - '0';
        // VISA starts with a 4.
        if (firstNum == 4)
        {
            response = "VISA\n";
        }
        // MasterCard numbers start with 51, 52, 53, 54, or 55.
        else if (firstNum == 5 && (secondNum == 1 || secondNum == 2 || secondNum == 3 || secondNum == 4 || secondNum == 5))
        {
            response = "MASTERCARD\n";
        }
        int total = calculate(num, card);
        response = total % 10 == 0 ? response : "INVALID\n";
    }
    else if (num == 15)
    {
        int firstNum = card[0] - '0';
        int secondNum = card[1] - '0';
        // American Express numbers start with 34 or 37.
        if (firstNum == 3 && (secondNum == 4 || secondNum == 7))
        {
            response = "AMEX\n";
        }
        int total = calculate(num, card);
        response = total % 10 == 0 ? response : "INVALID\n";
    }
    printf("%s", response);
}

// Every other digit starting from the second to last is multiplied by 2 and added together.
// The numbers that weren't multiplied are added to the sum. If the last digit of the sum is 0, it is a valid card.
// Returns the total.
int calculate(int num, string card)
{
    int total = 0;
    // Multiply every other digit by 2, starting with the number’s second-to-last
    // digit, and then add those products’ digits together
    for (int i = num - 2; i >= 0; i -= 2)
    {
        int current = card[i] - '0';
        current *= 2;
        int firstNum = current % 10;
        int secondNum = (current / 10) % 10;
        total += firstNum + secondNum;
    }
    // Add the sum to the sum of the digits that weren’t multiplied by 2.
    for (int j = num - 1; j >= 0; j -= 2)
    {
        int current = card[j] - '0';
        total += current;
    }
    return total;
}