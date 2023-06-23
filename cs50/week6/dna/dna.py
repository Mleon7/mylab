import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        sys.exit()

    csv_filename = sys.argv[1]
    text_filename = sys.argv[2]

    # TEST
    # csv_filename = "./week6/dna/databases/small.csv"
    # text_filename = "./week6/dna/sequences/3.txt"

    # TODO: Read database file into a variable
    with open(csv_filename, 'r') as csvfile:
        csv_reader = csv.DictReader(csvfile)
        csv_data = list(csv_reader)


    # TODO: Read DNA sequence file into a variable
    with open(text_filename, "r") as textfile:
        dna_sequences = textfile.read()

    # TODO: Find longest match of each STR in DNA sequence
    strs = []
    for i in range(1, len(csv_reader.fieldnames)):
        fieldname = csv_reader.fieldnames[i]
        strs.append(longest_match(dna_sequences, fieldname))

    # TODO: Check database for matching profiles
    is_match = False
    for i in range(len(csv_data)):
        match = 0 # 注意要在这里把match初始化为0
        for j in range(1, len(csv_reader.fieldnames)):
            fieldname = csv_reader.fieldnames[j]
            if strs[j - 1] == int(csv_data[i][fieldname]):
                match += 1
            if match == len(csv_reader.fieldnames) - 1: 
                print(csv_data[i]["name"])
                is_match = True
    
    if not is_match:
        print("No match")

    return


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
