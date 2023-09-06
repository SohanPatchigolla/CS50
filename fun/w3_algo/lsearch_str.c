#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    int n = 7;
    string s[] = {"race car", "thimble", "top hat", "iron", "boot", "cannon", "battleship"};

    string input = get_string("Enter a denomination: ");

    for (int i = 0; i < n; i++)
    {
        if (strcmp(s[i], input) == 0)
        {
            printf("Denomination '%s' is found\n", s[i]);
            return 0;
        }
    }

    return 1;
}