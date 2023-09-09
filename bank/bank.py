# Prompt the user for input
user_input = input("Enter a greeting: ")

# Remove leading whitespace and convert to lowercase
user_input = user_input.strip().lower()

# Check if the input starts with "hello" or "h" and output the corresponding amount
if user_input.startswith("hello"):
    print("$0")
elif user_input.startswith("h"):
    print("$20")
else:
    print("$100")
