#include <cs50.h>
#include <stdio.h>

int main(void)
{
    float counter = 0;

    char x = get_char("Type 'a' to add step count or 's' to subtract step count \n");

    if (x == 'a' || x == 'A')
    {
        float ini = get_float("Set initial number: ");
        float max = get_float("Set max number: ");
        float step = get_float("Set step increase: ");
        for (counter = ini; counter <= max; counter += step)
        {
            printf("%f", counter);
            printf("\n");
        }
    }
    else if (x == 's' || x == 'S')
    {
        printf("Please enter all values in float ex: 0.00 \n");
        float ini = get_float("Set initial number: ");
        float min = get_float("Set min number: ");
        float step = get_float("Set step decrease: ");
        for (counter = ini; counter >= min; counter -= step)
        {
            printf("%f", counter);
            printf("\n");
        }
    }
    else
    {
        printf("Enter 'a' or 's', you entered something else. \n");
    }
}