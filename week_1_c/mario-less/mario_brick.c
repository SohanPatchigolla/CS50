#include <stdio.h>
#include <cs50.h>

int get_size(void);
void print_brick(int s);

int main(void)
{
    // Gets size of the square brick

    int s = get_size();

    // Print the brick

    print_brick(s);
}

int get_size(void)
{
    int s;
    do
    {
        s = get_int("");
    }
    while (s < 1);
    return s;
}

void print_brick(s)
{
    for (int i = 0; i < s; i++)
    {
        for (int j = 0; j < s; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}










































