#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Gets name from user.
    string name = get_string("What's your name?: ");
    // Prints name.
    printf("hello, %s \n", name);
}