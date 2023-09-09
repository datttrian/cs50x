# TODO
from cs50 import get_int

def main():
    while True:
        height = get_int("Height: ")
        if height >= 1 and height <= 8:
            break

    for i in range(1, height + 1):
        num_hashes = i + 1
        num_spaces = width - num_hashes

        print(" " * num_spaces, end="")
        print("#" * num_hashes)


if __name__ == "__main__":
    main()