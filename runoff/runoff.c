#include <cs50.h>
#include <stdio.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
} candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    // TODO
    // Check if the name is a valid candidate name
    for (int i = 0; i < candidate_count; i++)
    {
        // Compare the provided name with the name of each candidate
        if (strcmp(name, candidates[i].name) == 0)
        {
            // Set the preference rank of the current voter to the candidate's index (i)
            preferences[voter][rank] = i;

            // Indicate a successful vote
            return true;
        }
    }

    // Indicate an invalid candidate name
    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    // TODO
    // Iterate through each voter's preferences
    for (int i = 0; i < voter_count; i++)
    {
        // Iterate through each rank of preference for the current voter
        for (int j = 0; j < candidate_count; j++)
        {
            // Get the index of the preferred candidate for this rank
            int preferred_candidate_index = preferences[i][j];

            // Check if the preferred candidate is eliminated
            if (!candidates[preferred_candidate_index].eliminated)
            {
                // If the preferred candidate is not eliminated, increment their vote count
                candidates[preferred_candidate_index].votes++;

                // Move to the next voter
                break;
            }
        }
    }
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    // TODO
    // Calculate the number of votes required for a majority
    int majority_votes = voter_count / 2 + 1;

    // Iterate through each candidate
    for (int i = 0; i < candidate_count; i++)
    {
        // Check if a candidate has received more votes than the majority
        if (candidates[i].votes >= majority_votes)
        {
            // Print the name of the winning candidate
            printf("%s\n", candidates[i].name);

            // Indicate that a winner has been found
            return true;
        }
    }

    // Indicate no candidate has a majority of votes
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    // TODO
    // Initialize min_votes to a very large value to ensure any candidate's votes will be smaller
    int min_votes = INT_MAX;

    // Iterate through each candidate
    for (int i = 0; i < candidate_count; i++)
    {
        // Check if the candidate is not eliminated and has fewer votes than the current minimum
        if (!candidates[i].eliminated && candidates[i].votes < min_votes)
        {
            // Update min_votes to the candidate's vote count
            min_votes = candidates[i].votes;
        }
    }

    // Return the minimum vote count among the remaining candidates
    return min_votes;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated && candidates[i].votes != min)
        {
            return false; // Not a tie
        }
    }
    return true; // It's a tie
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    // TODO
    // Iterate through each candidate
    for (int i = 0; i < candidate_count; i++)
    {
        // Check if the candidate has the same number of votes as the minimum
        if (candidates[i].votes == min)
        {
            // Mark the candidate as eliminated
            candidates[i].eliminated = true;
        }
    }
}
