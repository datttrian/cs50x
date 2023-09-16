menu = {
    "Baja Taco": 4.00,
    "Burrito": 7.50,
    "Bowl": 8.50,
    "Nachos": 11.00,
    "Quesadilla": 8.50,
    "Super Burrito": 8.50,
    "Super Quesadilla": 9.50,
    "Taco": 3.00,
    "Tortilla Salad": 8.00,
}

total_cost = 0.0

try:
    while True:
        item = input("Enter an item: ").strip()  # Prompt the user for input

        # Check if the input is empty
        if not item:
            continue

        # Convert the input to title case and look up the price in the menu
        price = menu.get(item.title())

        if price is not None:
            total_cost += price
            print(f"Total: ${total_cost:.2f}")
        else:
            print("Invalid item. Please choose from the menu.")
except EOFError:
    # User has inputted control-d, so we exit the loop
    pass
