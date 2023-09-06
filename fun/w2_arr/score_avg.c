#include <cs50.h>
#include <stdio.h>

const int N = 3;

float get_avg(int length, int array[]);

int main(void)
{
    // Gets test scores from a user.
    int scores[N];
    for (int i = 0; i < N; i++)
    {
        scores[i] = get_int("Enter score: ");
    }

    // Uses avg function, and prints average of the test scores.
    printf("Average is %f \n", get_avg(N, scores));
}

// Function to calculate the average of the array.
float get_avg(int length, int array[])
{
    int sum = 0;
    for (int j = 0; j < length; j++)
    {
        sum += array[j];
    }

    float avg_fun = sum / (float) length;

    return avg_fun;
}