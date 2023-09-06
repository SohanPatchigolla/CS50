#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name,name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }

    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    /*int s[candidate_count - 1];
    int c = 0;*/

    
    int cmp = round((candidate_count / 2)); // Possible bug here.
    printf("%i", cmp);

    int l[cmp];
    for (int i = 0; i < cmp; i++)
    {
        int l[i] = candidates[i+1].votes[i+1];
    }

    int rsize = candidate_count - cmp;
    int r[rsize];
    for (int i = 0; (i > cmp) && (i < candidate_count); i++)
    {
        int r[i] = candidates[i+1].votes[i+1];
    }

    // Sort.
    int temp = 0;

    for (int i = 0; i <= cmp; i++)
    {
        for (int j = 0; (j > cmp) && (j < candidate_count); j++)
        {
            if (l[i] > r[j])
            {
                temp = l[i];

                l[i] = r[j];

                r[j] = temp;
            }
            else if (l[i] < r[j])
            {
                temp = r[j];

                r[j] = l[i];

                l[i] = temp;
            }
        }
    }

   /* for (int i = 0; i < cmp; i++)
    {
        int n[count-1];

        if (l[i] > r[i])
        {
            n[i] = r[i];
        }
        else if (string l[i] < string r[i])
        {
            n[i] = l[i];
        }
    } */


    return;
}

//Sort

