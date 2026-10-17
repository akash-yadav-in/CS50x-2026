#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height = get_int("Height: ");

    if (height <= 0) // Checking wheter Height is less than 0 or not if less than or equal to 0 ask
                     // user the height again
    {
        height = get_int("Height: ");
    }

    if (height > 0) // If greater than 0 then run the below loops to print the "#"
    {
        for (int i = 0; i < height; i++)
        {
            for (int j = i + 1; j < height; j++) // This loop is for printing the spaces
            {
                printf(" ");
            }
            for (int m = 0; m < i + 1; m++) // This is for printing the hashes in the last
            {
                printf("#");
            }
            printf(
                "\n"); // This is for addition has and line end before the outermost loop runs again
        }
    }
}
