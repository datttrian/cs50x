# TODO
from cs50 import get_int

def main():
    while True:
        n = get_int("Height: ")
        if n >= 1 and n <= 8:
            break

    for row in range(1, n + 1):
        print(" " * (n-row), end="")
        print("#" * row)


if __name__ == "__main__":
    main()
    