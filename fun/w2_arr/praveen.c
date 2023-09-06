#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

int main(void)
{
    int minutesEntered = get_int("enter minutes: ");

    double minutesinyears = 60*24*365;
    double year = minutesEntered / minutesinyears;
    double day = (minutesEntered/60)/24;

    printf("%i is minutes entered, %f is minutes in years, %f is minutes in days \n", minutesEntered, year, day);
}