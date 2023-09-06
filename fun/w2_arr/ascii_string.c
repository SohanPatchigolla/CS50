#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string s = get_string("Enter the string: ");

    printf("The ASCII value of the string is: ");

    int i = 0;
    while (s[i] != '\0')
    {
        printf("%i ", s[i]);
        i++;
    }

    int temp = i;
    temp++;

    printf("%i", s[i]);

    printf("\n");

    printf("The size of the string is %i, including last char 'NULL' is %i.", i, temp);

    printf("\n");
}
