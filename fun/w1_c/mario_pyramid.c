#include <stdio.h>
#include <cs50.h>

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
    int rows;
    int columns;
    for (rows = 0 ; rows < h; rows++)
    {
        printf("%i ", rows);
        for (int s = (h - rows - 1); s > 0; s--)
        {
            printf(" ");
        }
        for (columns = 0; columns <= rows ;columns++)
        {
            printf("#");
            printf("#");
        }
        printf("\n");
    }
}





