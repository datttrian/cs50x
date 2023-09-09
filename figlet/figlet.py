# Import the sys module to access command-line arguments and the input function.
# Import the Figlet class from the pyfiglet library for ASCII art text rendering.
import sys
from pyfiglet import Figlet

# Create an instance of the Figlet class.
figlet = Figlet()

# Check the number of command-line arguments.
# If no arguments are provided, prompt the user to input text and render it using the default font.
if len(sys.argv) == 1:
    text = input("Text: ")
    print(figlet.renderText(text))
# If there are exactly three arguments, check if the first argument is "-f" or "--font"
# and if the second argument is a valid font name from the available fonts.
elif len(sys.argv) == 3:
    if (sys.argv[1] == "-f" or sys.argv[1] == "--font") and (
        sys.argv[2] in figlet.getFonts()
    ):
        # Prompt the user to input text and set the font to the specified font.
        text = input("Text: ")
        figlet.setFont(font=sys.argv[2])
        # Render the text using the specified font and print it.
        print(figlet.renderText(text))
    else:
        # If the arguments do not match the expected format, exit the script with an error message.
        sys.exit("Invalid usage")
else:
    # If the number of arguments is not 0 or 3, exit the script with an error message.
    sys.exit("Invalid usage")
