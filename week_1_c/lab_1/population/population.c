#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt for start size.
    int n;
    do
    {
        n = get_int("Start size: "); // n is the initial value.
    }
    while (n < 9);

    // Prompt for end size.
    int end;
    do
    {
        end = get_int("End size: ");
    }
    while (end < n);

    // Calculates number of years until we reach threshold.
    int count = 0;
    if (n == end)
    {
        printf("Years: 0");
    }
    else
    {
        int c;
        for (int i = 0; c < end; i++)
        {
            c = n + (n / 3) - (n / 4); // int c represents change per year.
            n = c;
            count++;
        }
    }

    // Prints number of years.
    printf("Years: %i", count);
}