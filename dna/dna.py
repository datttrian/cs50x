import csv
import sys


def main():

    # TODO: Check for command-line usage
    # Check for correct command-line usage
    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        return

    # Get filenames from command-line arguments
    database_filename = sys.argv[1]
    sequence_filename = sys.argv[2]

    # TODO: Read database file into a variable
    database = []
    with open(database_filename, newline="") as csvfile:
        reader = csv.DictReader(csvfile)
        for row in reader:
            database.append(row)

    # TODO: Read DNA sequence file into a variable
    with open(sequence_filename, "r") as sequence_file:
        dna_sequence = sequence_file.read()

    # TODO: Find longest match of each STR in DNA sequence
    # Initialize a dictionary to store the longest STR counts
    longest_counts = {}

    # Loop through each STR mentioned in the first row of the CSV file
    for str_name in database[0].keys():
        if str_name == "name":
            continue  # Skip the 'name' column
        longest_counts[str_name] = longest_match(dna_sequence, str_name)

    # TODO: Check database for matching profiles
    for person in database:
        match = True
        for str_name, str_count in longest_counts.items():
            if str_name == "name":
                continue
            if int(person[str_name]) != str_count:
                match = False
                break
        if match:
            print(person["name"])
            return

    # If no match is found in the loop, print "No match"
    print("No match")


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
