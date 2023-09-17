import csv
import requests


def main():
    # Read NYTimes Covid Database
    download = requests.get(
        "https://raw.githubusercontent.com/nytimes/covid-19-data/master/us-states.csv"
    )
    decoded_content = download.content.decode("utf-8")
    file = decoded_content.splitlines()
    reader = csv.DictReader(file)

    # Construct 14 day lists of new cases for each states
    new_cases = calculate(reader)

    # Create a list to store selected states
    states = []
    print("Choose one or more states to view average COVID cases.")
    print("Press enter when done.\n")

    while True:
        state = input("State: ")
        if state in new_cases:
            states.append(state)
        if len(state) == 0:
            break

    print(f"\nSeven-Day Averages")

    # Print out 7-day averages for this week vs last week
    comparative_averages(new_cases, states)


# TODO: Create a dictionary to store 14 most recent days of new cases by state
def calculate(reader):
    new_cases = {}
    previous_cases = {}

    for row in reader:
        state = row["state"]
        cases = int(row["cases"])

        if state not in new_cases:
            new_cases[state] = []
            previous_cases[state] = 0

        # Calculate new cases for the current day
        new_day_cases = cases - previous_cases[state]
        new_cases[state].append(new_day_cases)

        # Keep only the last 14 days of new cases
        if len(new_cases[state]) > 14:
            new_cases[state].pop(0)

        # Update the previous cases for the next iteration
        previous_cases[state] = cases

    return new_cases


# TODO: Calculate and print out seven day average for given state
def comparative_averages(new_cases, states):
    for state in states:
        try:
            # Calculate this week's average
            this_week_avg = sum(new_cases[state][-7:]) / 7
            # Calculate last week's average
            last_week_avg = sum(new_cases[state][-14:-7]) / 7
            # Calculate the percent change
            percent_change = ((this_week_avg - last_week_avg) / last_week_avg) * 100

            print(
                f"{state} had a 7-day average of {int(this_week_avg)} and a change of {int(percent_change)}%."
            )
        except ZeroDivisionError:
            print(f"{state} data is insufficient to calculate the 7-day average.")


if __name__ == "__main__":
    main()