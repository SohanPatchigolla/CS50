#include <cs50.h>
#include <stdio.h>

int get_height(void);
void print_pyramid_left(int h);

int main(void)
{
    // Get height from user
    int Height = get_height();

    // Prints pyramid
    print_pyramid_left(Height);
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

void print_pyramid_left(h)
{
    for (int rows = 0 ; rows < h; rows++)
    {
        for (int columns = 0; columns <= rows ;columns++)
        {
            printf("#");
        }
        printf("\n");
    }
}
