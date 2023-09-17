#include <cs50.h>
#include <stdio.h>
#include <string.h>

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
} pair;

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
bool is_cycle(int winner, int loser); // helper function to check if adding a pair creates a cycle
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
    // Check if the name is a valid candidate
    for (int i = 0; i < candidate_count; i++) // loop through all candidates
    {
        if (strcmp(name, candidates[i]) == 0) // compare the voter's choice (name) with each candidate
        {
            // Update the ranks array with the candidate's index as the rank preference
            ranks[rank] = i; // assign the candidate's index to the specified rank
            return true;     // vote recorded successfully
        }
    }
    return false; // invalid vote
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // TODO
    for (int i = 0; i < candidate_count; i++) // loop through all candidates
    {
        for (int j = i + 1; j < candidate_count; j++) // loop through all remaining candidates
        {
            // Increment the preference count for the pair of candidates
            preferences[ranks[i]][ranks[j]]++; // increase the preference count for this pair
        }
    }
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // TODO
    int pair_index = 0;                       // initialize a variable to keep track of the pair index
    for (int i = 0; i < candidate_count; i++) // loop through all candidates
    {
        for (int j = i + 1; j < candidate_count; j++) // loop through all remaining candidates
        {
            if (preferences[i][j] > preferences[j][i]) // check if candidate 'i' is preferred over 'j'
            {
                // Store the pair where 'i' is the winner and 'j' is the loser
                pairs[pair_index].winner = i; // store the winner
                pairs[pair_index].loser = j;  // store the loser
                pair_index++;                 // move to the next pair
            }
            else if (preferences[i][j] < preferences[j][i]) // check if candidate 'j' is preferred over 'i'
            {
                // Store the pair where 'j' is the winner and 'i' is the loser
                pairs[pair_index].winner = j; // store the winner
                pairs[pair_index].loser = i;  // store the loser
                pair_index++;                 // move to the next pair
            }
        }
    }
    pair_count = pair_index; // update the pair count
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // TODO
    for (int i = 0; i < pair_count - 1; i++) // loop through all pairs
    {
        for (int j = i + 1; j < pair_count; j++) // loop through remaining pairs
        {
            int strength_i = preferences[pairs[i].winner][pairs[i].loser]; // get strength of victory for pair 'i'
            int strength_j = preferences[pairs[j].winner][pairs[j].loser]; // get strength of victory for pair 'j'

            if (strength_i < strength_j) // compare strength of victory
            {
                // Swap pairs to sort them by strength of victory
                pair temp = pairs[i]; // temporary storage for pair 'i'
                pairs[i] = pairs[j];  // swap pair 'i' with pair 'j'
                pairs[j] = temp;      // assign pair 'j' to the temporary storage
            }
        }
    }
}

// Helper function to check if adding a pair creates a cycle
bool is_cycle(int winner, int loser)
{
    if (winner == loser) // check if it's a self-loop
    {
        return true; // a self-loop creates a cycle
    }

    if (locked[loser][winner]) // check if adding this pair would create a cycle
    {
        return true;
    }

    for (int i = 0; i < candidate_count; i++) // loop through all candidates
    {
        if (locked[i][winner] && is_cycle(i, loser)) // check for cycles recursively
        {
            return true; // recursive check for cycles
        }
    }

    return false; // no cycle found
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO
    for (int i = 0; i < pair_count; i++) // loop through all pairs
    {
        if (!is_cycle(pairs[i].winner, pairs[i].loser)) // check if adding the pair creates a cycle
        {
            locked[pairs[i].winner][pairs[i].loser] = true; // lock the pair in the candidate graph
        }
    }
}

// Print the winner of the election
void print_winner(void)
{
    // TODO
    for (int i = 0; i < candidate_count; i++) // loop through all candidates
    {
        bool is_source = true;                    // assume the candidate is a source (has no incoming edges)
        for (int j = 0; j < candidate_count; j++) // loop through all candidates
        {
            if (locked[j][i]) // check if there's a directed edge from j to i
            {
                is_source = false; // candidate is not a source
                break;             // no need to check further for this candidate
            }
        }
        if (is_source)
        {
            // Print the candidate who is a source (has no incoming edges)
            printf("%s\n", candidates[i]);
            return; // exit the function
        }
    }
}
