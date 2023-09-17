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
    owned = db.execute(
        "SELECT stock,number FROM owned WHERE user_id = ?", session["user_id"]
    )
    total = 0
    for stock in owned:
        stock["price"] = lookup(stock["stock"])["price"]
        stock["value"] = stock["price"] * stock["number"]
        total += stock["value"]
        stock["value"] = usd(stock["price"] * stock["number"])
    cash = db.execute("SELECT cash FROM users WHERE id=?", session["user_id"])
    total += cash[0]["cash"]
    total = usd(total)
    return render_template(
        "index.html", owned=owned, cash=usd(cash[0]["cash"]), total=total
    )


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
    return apology("TODO")


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
    return apology("TODO")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    return apology("TODO")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    return apology("TODO")
