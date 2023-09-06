#include <stdio.h>
#include <cs50.h>

int main(void)
{
    double x = get_double("Enter the number X: ");
    double y = get_double("Enter the number Y: ");

    if (x > y)
    {
        printf("%lf is greater than %lf \n", x, y);
    }
    else if (y > x)
    {
        printf("%lf is greater than %lf \n", y, x);
    }
    else
    {
        printf("%lf is equal %lf or the number is longer than double \n", x, y);
    }
}