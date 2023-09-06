#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>


int get_letters(string s);
int get_words(string s);
int get_sentences(string s);
void print_grade(int i);

int main(void)
{
    // Gets string of text as input from the user.
    string text = get_string("Text: ");

    // Gets input from functions.
    float letters = get_letters(text);
    // Use this statement to check the count of letters: printf("letters: %f \n", letters);
    float words = get_words(text);
    // Use this statement to check the count of words: printf("words: %f \n", words);
    float sentences = get_sentences(text);
    // Use this statement to check the count of sentences: printf("sentences: %f \n", sentences);

    // Calculates average number of letters per 100 words.
    float L = (letters / words) * 100;
    // Calculates average number of sentences per 100 words.
    float S = (sentences / words) * 100;

    // Calculates Grade with help of Coleman-Liau index.
    double index = (0.0588 * L) - (0.296 * S) - (15.8);

    int grade = round(index);

    // Prints grade.
    print_grade((grade));
}

void print_grade(int i)
{
    if (i < 0)
    {
        printf("Before Grade 1\n");
    }
    else if (i > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", i);
    }
}
// Calculates number of letters in a given string.
int get_letters(string s)
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

    // Calculate count of letters
    int count = 0;
    for (int j = 0, len = strlen(s); j < len; j++)
    {
        if (isalpha(s[j]))
        {
            for (int i = 0; i < a; i++)
            {
                if (((int) s[j] == al_low[i]) || ((int) s[j] == al_up[i]))
                {
                    count++;
                }
            }
        }
        else
        {
            count += 0;
        }
    }

    return count;
}

// Calculates number of words in a given string.
int get_words(string s)
{
    int count = 0;
    for (int j = 0, len = strlen(s); j < len; j++)
    {
        if (s[j] == ' ')
        {
            count++;
        }
    }

    count++;

    return count;
}

// Calculates number of sentences in a given string.
int get_sentences(string s)
{
    int count = 0;
    for (int j = 0, len = strlen(s); j < len; j++)
    {
        if ((s[j] == '.') || (s[j] == '!') || (s[j] == '?'))
        {
            count++;
        }
    }

    return count;
}