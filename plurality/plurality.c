#include <cs50.h>
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
    // TODO
    // printf("%i\n", candidate_count);
    for (int i = 0; i < candidate_count; i++) {
        // printf("%s is name and %s is %ith candidate\n", name, candidates[i].name, i);
        if (strcmp(name, candidates[i].name) == 0) {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // TODO
    printf("print_winner() running\n");
    int max_vote = 0, max_vot_index = 0;
    int max_same_ind_array[candidate_count + 1], max_sm_indx_count = 0;
    int winer_count = 1;
    for (int i = 0; i < candidate_count; i++)
    {
        if (i != 0 && candidates[i].votes == candidates[max_vot_index].votes)
        {
            max_same_ind_array[max_sm_indx_count] = i;
            max_same_ind_array[++max_sm_indx_count] = '\0';
            winer_count++;
        }
        else if (candidates[i].votes > max_vote)
        {
            max_same_ind_array[max_sm_indx_count] = i;
            max_same_ind_array[++max_sm_indx_count] = '\0';
            max_vote = candidates[i].votes;
            max_vot_index = i;
        }
    }
    printf("%i\n", max_same_ind_array[max_sm_indx_count - 1]);
    printf("%i\n", max_same_ind_array[max_sm_indx_count]);
    if (winer_count == 1)
        printf("%s is the winner with %i votes\n", candidates[max_vot_index].name, candidates[max_vot_index].votes);
    else
    {
        printf("Winners are");
        for (int i = 0; i < max_sm_indx_count; i++)
        {
            printf(" %s", candidates[max_same_ind_array[i]].name);
            // printf(" %i", max_same_ind_array[i]);
        }
        printf("\n");
    }
    return;
}
