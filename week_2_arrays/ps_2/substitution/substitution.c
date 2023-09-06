#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

string replace(string plain, string key);
int check(string key, int key_len);

// Main function makesures the given specifications are met and prints the output.
int main(int argc, string argv[])
{
    const int len = 26; // Corrected by ChatGPT

    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    int key_len = strlen(argv[1]);
    if (key_len != len)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    for (int i = 0; i < key_len; i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("Key must contain alphabets only\n");
            return 1;
        }
    }

    int c = check(argv[1], key_len);
    if (c == 1)
    {
        printf("Key must contain unique alphabets\n");
        return 1;
    }

    string plaintext = get_string("plaintext: ");
    string ciphertext = replace(plaintext, argv[1]);
    printf("ciphertext: %s\n", ciphertext);

    return 0;
}

// This functions converts plaintext with ciphertext with the given key.
string replace(string plain, string key)
{
    const int a = 26;
    const int b = 25;

    // Insert ASCII values of a-z in array al_low[].
    int al_low[b];
    int c1;
    for (int x = 97, c1 = 0; c1 < a; x++, c1++)
    {
        al_low[c1] = x;
    }

    // Insert ASCII values of A-Z in array al_up[].
    int al_up[b];
    int c2;
    for (int y = 65, c2 = 0; c2 < a; y++, c2++)
    {
        al_up[c2] = y;
    }

    int len = strlen(plain);
    string cipher = malloc(len + 1);
    //  malloc() provides a block of raw memory but it doesn't automatically set the null-terminator.
    cipher[len] = '\0';

    for (int j = 0; j < len; j++)
    {
        for (int i = 0; i < a; i++)
        {
            if ((int) plain[j] == al_low[i])
            {
                cipher[j] = tolower(key[i]);
                break; // Corrected by ChatGPT
            }
            else if ((int) plain[j] == al_up[i])
            {
                cipher[j] = toupper(key[i]);
                break; // Corrected by ChatGPT
            }
            else
            {
                cipher[j] = plain[j]; // Corrected by ChatGPT
            }
        }
    }

    return cipher;
}

// This function checks for duplicate characters.
int check(string key, int key_len)
{
    for (int i = 0; i < key_len; i++)
    {
        for (int j = i + 1; j < key_len; j++)
        {
            if (key[i] == key[j])
            {
                return 1; // Duplicate characters foud.
            }
        }
    }

    return 0; // All characters are unique.
}
