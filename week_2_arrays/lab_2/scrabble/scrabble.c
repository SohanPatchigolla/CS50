#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);
void print_winner(int s1, int s2);

int main(void)
{
    // Gets a word as input from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Assigns the computed scores to the variables.
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Prints the winner
    print_winner(score1, score2);
}

// Compute and return score for string
int compute_score(string word)
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

    // Calculates the score for the given word.
    int score = 0;
    for (int j = 0, len = strlen(word); j < len; j++)
    {
        if (isalpha(word[j]))
        {
            for (int i = 0; i < a; i++)
            {
                if (((int) word[j] == al_low[i]) || ((int) word[j] == al_up[i]))
                {
                    score = score + POINTS[i];
                }
            }
        }
        else
        {
            score += 0;
        }
    }
    // Use this statement to check score: printf("%i \n", score);
    return score;
}

// Function to print winner.
void print_winner(int s1, int s2)
{
    if (s1 > s2)
    {
        printf("Player 1 wins! \n");
    }
    else if (s2 > s1)
    {
        printf("Player 2 wins! \n");
    }
    else
    {
        printf("Tie! \n");
    }
}
