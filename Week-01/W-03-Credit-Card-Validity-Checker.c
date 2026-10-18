#include <cs50.h>
#include <stdio.h>

// Simplified and corrected Luhn's Algorithm check
bool Legit_check(long long a)
{
    int sum_left_last_two_digit = 0;
    int other_digit_sum = 0;
    bool multiply_by_two = false;

    while (a > 0)
    {
        int last_digit = a % 10;

        if (multiply_by_two)
        {
            int product = last_digit * 2;
            // If the product is 2 digits we have to  add its individual digits
            sum_left_last_two_digit += (product % 10) + (product / 10);
        }
        else
        {
            // Just add the digits that weren't multiplied
            other_digit_sum += last_digit;
        }

        // Alternate for the next digit
        multiply_by_two = !multiply_by_two;

        // Move to the next digit to the left
        a = a / 10;
    }

    // Check if the total ends in 0
    return ((sum_left_last_two_digit + other_digit_sum) % 10 == 0);
}

int main(void)
{
    // Getting user credit card details
    long long credit = get_long_long("Number: ");
    long long restore = credit;

    // Count the total number of digits
    int digit_counter = 0;
    while (credit > 0)
    {
        credit = credit / 10;
        digit_counter++;
    }

    // Is the length even valid
    if (digit_counter != 13 && digit_counter != 15 && digit_counter != 16)
    {
        printf("INVALID\n");
        return 0;
    }

    // Getting  the first 2 digits (and the first 1 digit)
    long long starting_digits = restore;
    while (starting_digits >= 100)
    {
        starting_digits /= 10;
    }

    int first_two_digits = starting_digits;
    int first_digit = starting_digits / 10;

    // Perform the Luhn validation check first
    if (!Legit_check(restore))
    {
        printf("INVALID\n");
        return 0;
    }

    // Identify Card
    if (digit_counter == 15 && (first_two_digits == 34 || first_two_digits == 37))
    {
        printf("AMEX\n");
    }
    else if (digit_counter == 16 && (first_two_digits >= 51 && first_two_digits <= 55))
    {
        printf("MASTERCARD\n");
    }
    else if ((digit_counter == 13 || digit_counter == 16) && first_digit == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
