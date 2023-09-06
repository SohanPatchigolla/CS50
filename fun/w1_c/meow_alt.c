#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int counter = get_int("number of pats \n");
    while (counter > 0)
    {
        printf("meow \n");
        counter--;
    }
}