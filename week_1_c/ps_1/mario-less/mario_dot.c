#include <cs50.h>
#include <stdio.h>

int get_height(void);
void print_pyramid(int h);

int main(void)
{
    // Get height from user
    int Height = get_height();

    // Prints pyramid
    print_pyramid(Height);
}

int get_height(void)
{
    int h;
    do
    {
        h = get_int("Height: ");
    }
    while (h < 1 || h > 8);
    return h;
}

void print_pyramid(h)
{
    for (int rows = 0 ; rows < h; rows++)
    {
        for (int s = (h - rows - 1); s > 0; s--)
        {
            printf(".");
        }
        for (int columns = 0; columns <= rows ;columns++)
        {
            printf("#");
        }
        printf("\n");
    }
}
