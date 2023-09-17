import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    # return apology("TODO")
    # Query the database to get a list of owned stocks and their quantities for the current user
    owned = db.execute("SELECT stock, number FROM owned WHERE user_id = ?", session["user_id"])
    
    # Initialize a variable to keep track of the total portfolio value
    total = 0
    
    # Iterate through the user's owned stocks
    for stock in owned:
        # Look up the current stock's price and update the stock dictionary
        stock["price"] = lookup(stock["stock"])["price"]
        
        # Calculate the value of the user's holdings for this stock
        stock["value"] = stock["price"] * stock["number"]
        
        # Update the total portfolio value with the value of this stock
        total += stock["value"]
        
        # Format the value of this stock as USD
        stock["value"] = usd(stock["value"])
    
    # Query the database to get the user's cash balance
    cash = db.execute("SELECT cash FROM users WHERE id=?", session["user_id"])
    
    # Add the cash balance to the total portfolio value
    total += cash[0]["cash"]
    
    # Format the total portfolio value as USD
    total = usd(total)
    
    # Render the index.html template with the user's portfolio data
    return render_template("index.html", owned=owned, cash=usd(cash[0]["cash"]), total=total)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "POST":
        if not request.form.get("symbol"):
            return apology("must provide a stock", 400)
        elif not lookup(request.form.get("symbol")):
            return apology("no such stock", 400)
        elif not request.form.get("shares"):
            return apology("How many bro", 400)
        elif not request.form.get("shares").isnumeric():
            return apology("must enter a number", 400)
        elif int(request.form.get("shares")) <= 0:
            return apology("must buy at least one", 400)
        stock = request.form.get("symbol")
        price = lookup(request.form.get("symbol"))["price"] * int(
            request.form.get("shares")
        )
        rows = db.execute("SELECT cash from users WHERE id = ?", session["user_id"])
        if price > rows[0]["cash"]:
            return apology("not enough funds", 400)
        else:
            cash = rows[0]["cash"] - price
            db.execute(
                "UPDATE users SET cash = ? WHERE id = ?", cash, session["user_id"]
            )
            data = db.execute(
                "SELECT number FROM owned WHERE user_id = ? AND stock = ?",
                session["user_id"],
                request.form.get("symbol"),
            )
            if data:
                db.execute(
                    "UPDATE owned SET number = ? WHERE user_id = ? AND stock = ?",
                    data[0]["number"] + int(request.form.get("shares")),
                    session["user_id"],
                    request.form.get("symbol"),
                )
            else:
                db.execute(
                    "INSERT INTO owned (user_id,stock,number) VALUES (?,?,?)",
                    session["user_id"],
                    request.form.get("symbol"),
                    int(request.form.get("shares")),
                )
            now = datetime.now()
            date_time = now.strftime("%m/%d/%Y, %H:%M:%S")
            db.execute(
                "INSERT INTO transactions (user_id,type,name,price,time,number) VALUES (?,'Bought',?,?,?,?)",
                session["user_id"],
                request.form.get("symbol"),
                lookup(request.form.get("symbol"))["price"],
                date_time,
                int(request.form.get("shares")),
            )
            return redirect("/")
    else:
        return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    # return apology("TODO")
    transactions = db.execute(
        "SELECT * FROM transactions WHERE user_id = ?", session["user_id"]
    )
    return render_template("history.html", transactions=transactions)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    # return apology("TODO")
    # Check if the request method is POST (data submission)
    if request.method == "POST":
        # Check if the "symbol" field is empty
        if not request.form.get("symbol"):
            return apology("must provide a stock symbol", 400)  # return an error if symbol is missing
        # Look up the stock symbol in the database
        if lookup(request.form.get("symbol")):
            stock = lookup(request.form.get("symbol"))
            stock["price"] = usd(stock["price"])  # format the stock price as USD
            return render_template("quoted.html", stock=stock)  # render the quoted.html template with stock data
        else:
            return apology("No such stock symbol", 400)  # return an error if the symbol is not found
    else:
        return render_template("quote.html")  # render the quote.html template for the initial GET request


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    if request.method == "POST":
        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 400)  # return an error if username is missing

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 400)  # return an error if password is missing

        # Ensure password confirmation was submitted
        elif not request.form.get("confirmation"):
            return apology("must confirm your password", 400)  # return an error if confirmation is missing

        # Ensure password and confirmation match
        elif request.form.get("confirmation") != request.form.get("password"):
            return apology("must check your password again", 400)  # return an error if passwords do not match

        # Check if the username is already in use
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))
        if rows:
            return apology("username already used", 400)  # return an error if the username is already taken

        # If all checks pass, insert the new user into the database
        db.execute(
            "INSERT INTO users (username, hash) VALUES (?, ?)",
            request.form.get("username"),
            generate_password_hash(request.form.get("password")),
        )

        # Query the database to get the new user's ID
        number = db.execute("SELECT id FROM users WHERE username = ?", request.form.get("username"))

        # Store the user's ID in the session
        session["user_id"] = number[0]["id"]

        # Redirect the user to the homepage
        return redirect("/")
    else:
        # Render the registration page if the request method is not POST
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    return apology("TODO")
