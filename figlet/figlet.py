import sys
from pyfiglet import Figlet


def print_usage_and_exit():
    print("Invalid usage")
    sys.exit(1)


if len(sys.argv) == 1:
    # No command-line arguments, use a random font
    font_name = None
elif len(sys.argv) == 3 and (sys.argv[1] == "-f" or sys.argv[1] == "--font"):
    # Two command-line arguments with -f or --font option, use the specified font
    font_name = sys.argv[2]
else:
    print_usage_and_exit()

user_text = input("Enter text: ")

figlet = Figlet(font=font_name) if font_name else Figlet()
output_text = figlet.renderText(user_text)
print(output_text)
