# TODO
from cs50 import get_int


def main():
    # Display "Height: " to prompt the user to input a positive integer between 1 and 8 and store it in n
    while True:
        n = get_int("Height: ")
        if 1 <= n <= 8:
            break

    # For each row from '1' to 'n'
    for row in range(1, n + 1):
        spaces = " " * (n - row)
        left_hashes = "#" * row
        right_hashes = "#" * row

        # Print 'n - row' spaces, 'row' hash symbols, 'two' spaces, 'row' hash symbols ('#')
        print(f"{spaces}{left_hashes}  {right_hashes}")


if __name__ == "__main__":
    main()
