# TODO
from cs50 import get_int


def main():
    # Display "Height: " to prompt the user input a positive integer between 1 and 8 and store it in n
    while True:
        n = get_int("Height: ")
        if 1 <= n <= 8:
            break

    # For each row from '1' to 'n'
    for row in range(1, n + 1):
        spaces = " " * (n - row)
        left_hashes = "#" * row

        # Print 'n - row' spaces and 'row' hash symbols
        print(f"{spaces}{left_hashes}")


if __name__ == "__main__":
    main()
