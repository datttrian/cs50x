#include <cs50.h>
#include <stdio.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
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
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // TODO
    // Loop through the candidates to find a match for the given name
    for (int i = 0; i < candidate_count; i++)
    {
        // Compare the candidate name with the given name
        if (strcmp(candidates[i], name) == 0)
        {
            // If a match is found, update the ranks array with the candidate's index as the rank preference
            ranks[rank] = i;
            // Return true to indicate a successful vote recording
            return true;
        }
    }
    // If no match is found, return false to indicate an invalid vote
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // TODO
    // Iterate through the ranks of the current voter
    for (int i = 0; i < candidate_count; i++)
    {
        // Compare each pair of candidates in the voter's ranks
        for (int j = i + 1; j < candidate_count; j++)
        {
            // Increase the preference count for the candidate at ranks[i] over ranks[j]
            preferences[ranks[i]][ranks[j]]++;
        }
    }
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // TODO
    // Iterate through pairs of candidates
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            // Check if preferences indicate candidate i is preferred over candidate j
            if (preferences[i][j] > preferences[j][i])
            {
                // Record this pair with i as the winner and j as the loser
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                // Increment the pair_count
                pair_count++;
            }
            // Check if preferences indicate candidate j is preferred over candidate i
            else if (preferences[i][j] < preferences[j][i])
            {
                // Record this pair with j as the winner and i as the loser
                pairs[pair_count].winner = j;
                pairs[pair_count].loser = i;
                // Increment the pair_count
                pair_count++;
            }
        }
    }
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // TODO
    // Bubble sort algorithm to sort pairs based on the strength of victory
    for (int i = 0; i < pair_count - 1; i++)
    {
        for (int j = 0; j < pair_count - i - 1; j++)
        {
            int margin1 = preferences[pairs[j].winner][pairs[j].loser];
            int margin2 = preferences[pairs[j + 1].winner][pairs[j + 1].loser];

            // Swap pairs if margin1 is less than margin2, ensuring descending order
            if (margin1 < margin2)
            {
                pair temp = pairs[j];
                pairs[j] = pairs[j + 1];
                pairs[j + 1] = temp;
            }
        }
    }
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO
    return;
}

// Print the winner of the election
void print_winner(void)
{
    // TODO
    return;
}