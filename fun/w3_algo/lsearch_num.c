#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n = 7;
    int number[] = {20 , 50, 100, 5, 500, 10, 1};

    int input = get_int("Enter a denomination: ");

    for (int i = 0; i < n; i++)
    {
        if (number[i] == input)
        {
            printf("Denomination '%i' is found\n", number[i]);
            return 0;
        }
    }

    return 1;
}