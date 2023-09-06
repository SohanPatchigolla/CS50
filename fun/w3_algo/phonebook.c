#include <cs50.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    string name;
    string number;
}
person;

int main(void)
{
    int max = 3;
    person p[3];

    p[0].name = "sohan";
    p[0].number = "+91-8317505314";

    p[1].name = "praveen";
    p[1].number = "+91-1111100000";

    p[2].name = "althaf";
    p[2].number = "+91-0000011111";

    string input = get_string("Enter name to search: ");

    for (int i = 0; i < max; i++)
    {
        if (strcmp(p[i].name, input) == 0)
        {
            printf("Found '%s', number is: %s\n", p[i].name, p[i].number);
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}