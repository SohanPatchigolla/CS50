#include <cs50.h>
#include <stdio.h>

int main(void)
{
    char a = get_char("Type 'y' if you agree or 'n' to disagree \n");

    if (a == 'y' || a== 'Y')
    {
        printf("you have agreed. \n");
    }
    else if (a == 'n' || a == 'N')
    {
        printf("you have disagreed. \n");
    }
    else
    {
        printf("Enter Y or N, you entered something else. \n");
    }
}