# TODO
import re
from cs50 import get_string


def main():
    text = get_string("Text: ")

    letters = len(re.findall(r"[a-zA-Z]", text))
    words = len(text.split())
    sentences = len(re.findall(r"[.!?]", text))

    L = (letters / words) * 100
    S = (sentences / words) * 100

    index = 0.0588 * L - 0.296 * S - 15.8

    grade_level = round(index)

    if grade_level < 1:
        print("Before Grade 1")
    elif grade_level >= 16:
        print("Grade 16+")
    else:
        print(f"Grade {grade_level}")


if __name__ == "__main__":
    main()
