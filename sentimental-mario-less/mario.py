# TODO
def main():
    # Prompt the user for the half-pyramid's height
    while True:
        height = get_height()
        if height >= 1 and height <= 8:
            break

    # Generate the half-pyramid
    for i in range(1, height + 1):
        spaces = " " * (height - i)
        hashes = "#" * i
        print(spaces + hashes)


def get_height():
    try:
        height = int(input("Height: "))
        return height
    except ValueError:
        return -1


if __name__ == "__main__":
    main()
