# [Lab 2: Scrabble](#lab-2-scrabble)

You are welcome to collaborate with one or two classmates on this lab,
though it is expected that every student in any such group contribute
equally to the lab.

Determine which of two Scrabble words is worth more.

``` highlight
$ ./scrabble
Player 1: COMPUTER
Player 2: science
Player 1 wins!
```

## [Getting Started](#getting-started)

Open [VS Code](https://cs50.dev/).

Start by clicking inside your terminal window, then execute `cd` by
itself. You should find that its “prompt” resembles the below.

``` highlight
$
```

Click inside of that terminal window and then execute

``` highlight
wget https://cdn.cs50.net/2022/fall/labs/2/scrabble.zip
```

followed by Enter in order to download a ZIP called `scrabble.zip` in
your codespace. Take care not to overlook the space between `wget` and
the following URL, or any other character for that matter!

Now execute

``` highlight
unzip scrabble.zip
```

to create a folder called `scrabble`. You no longer need the ZIP file,
so you can execute

``` highlight
rm scrabble.zip
```

and respond with “y” followed by Enter at the prompt to remove the ZIP
file you downloaded.

Now type

``` highlight
cd scrabble
```

followed by Enter to move yourself into (i.e., open) that directory.
Your prompt should now resemble the below.

``` highlight
scrabble/ $
```

If all was successful, you should execute

``` highlight
ls
```

and you should see a file called `scrabble.c`. Open that file by
executing the below:

``` highlight
code scrabble.c
```

If you run into any trouble, follow these same steps steps again and see
if you can determine where you went wrong!

## [Background](#background)

In the game of [Scrabble](https://scrabble.hasbro.com/en-us/rules),
players create words to score points, and the number of points is the
sum of the point values of each letter in the word.

|  **A**  |  **B**  |  **C**  |  **D**  |  **E**  |  **F**  |  **G**  |  **H**  |  **I**  |  **J**  |  **K**  |  **L**  |  **M**  |  **N**  |  **O**  |  **P**  |  **Q**  |  **R**  |  **S**  |  **T**  |  **U**  |  **V**  |  **W**  |  **X**  |  **Y**  |  **Z**  |
|---------|---------|---------|---------|---------|---------|---------|---------|---------|---------|---------|---------|---------|---------|---------|---------|---------|---------|---------|---------|---------|---------|---------|---------|---------|---------|
|    1    |    3    |    3    |    2    |    1    |    4    |    2    |    4    |    1    |    8    |    5    |    1    |    3    |    1    |    1    |    3    |   10    |    1    |    1    |    1    |    1    |    4    |    4    |    8    |    4    |   10    |


For example, if we wanted to score the word `Code`, we would note that
in general Scrabble rules, the `C` is worth `3` points, the `o` is worth
`1` point, the `d` is worth `2` points, and the `e` is worth `1` point.
Summing these, we get that `Code` is worth `3 + 1 + 2 + 1 = 7` points.

## [Implementation Details](#implementation-details)

Complete the implementation of `scrabble.c`, such that it determines the
winner of a short scrabble-like game, where two players each enter their
word, and the higher scoring player wins.

- Notice that we’ve stored the point values of each letter of the
  alphabet in an integer array named `POINTS`.
  - For example, `A` or `a` is worth 1 point (represented by
    `POINTS[0]`), `B` or `b` is worth 3 points (represented by
    `POINTS[1]`), etc.
- Notice that we’ve created a prototype for a helper function called
  `compute_score()` that takes a string as input and returns an `int`.
  Whenever we would like to assign point values to a particular word, we
  can call this function. Note that this prototype is required for C to
  know that `compute_score()` exists later in the program.
- In `main()`, the program prompts the two players for their words using
  the `get_string()` function. These values are stored inside variables
  named `word1` and `word2`.
- In `compute_score()`, your program should compute, using the `POINTS`
  array, and return the score for the string argument. Characters that
  are not letters should be given zero points, and uppercase and
  lowercase letters should be given the same point values.
  - For example, `!` is worth `0` points while `A` and `a` are both
    worth `1` point.
  - Though Scrabble rules normally require that a word be in the
    dictionary, no need to check for that in this problem!
- In `main()`, your program should print, depending on the players’
  scores, `Player 1 wins!`, `Player 2 wins!`, or `Tie!`.

### [Walkthrough](#walkthrough)

This video was recorded when the course was still using CS50 IDE for
writing code. Though the interface may look different from your
codespace, the behavior of the two environments should be largely
similar!

[ CS50 Video Player](/)

-  Shortcuts

&nbsp;

- Snacks

&nbsp;

-

- [](https://video.cs50.io/RtjxxxlN1gc)

##### Shortcuts

Before using a shortcut, click at least once on the video itself (to
give it "focus") after closing this window.

|                               |                         |
|-------------------------------|-------------------------|
| Play/Pause                    | spacebar or k           |
| Rewind 10 seconds             | left arrow or j         |
| Fast forward 10 seconds       | right arrow or l        |
| Previous frame (while paused) | ,                       |
| Next frame (while paused)     | .                       |
| Decrease playback rate        | \<                      |
| Increase playback rate        | \>                      |
| Toggle captions on/off        | c                       |
| Toggle mute                   | m                       |
| Toggle full screen            | f or double-click video |

### [Hints](#hints)

-

  You may find the functions `isupper()` and `islower()` to be helpful
  to you. These functions take in a character as the argument and return
  a boolean.

-

  To find the value at the `n`th index of an array called `arr`, we can
  write `arr[n]`. We can apply this to strings as well, as strings are
  arrays of characters.

-

  Recall that computers represent characters using
  [ASCII](https://asciitable.com/), a standard that represents each
  character as a number.

Not sure how to solve?

[ CS50 Video Player](/)

-  Shortcuts

&nbsp;

- Snacks

&nbsp;

-

- [](https://video.cs50.io/USiLkXuXJEg)

##### Shortcuts

Before using a shortcut, click at least once on the video itself (to
give it "focus") after closing this window.

|                               |                         |
|-------------------------------|-------------------------|
| Play/Pause                    | spacebar or k           |
| Rewind 10 seconds             | left arrow or j         |
| Fast forward 10 seconds       | right arrow or l        |
| Previous frame (while paused) | ,                       |
| Next frame (while paused)     | .                       |
| Decrease playback rate        | \<                      |
| Increase playback rate        | \>                      |
| Toggle captions on/off        | c                       |
| Toggle mute                   | m                       |
| Toggle full screen            | f or double-click video |

### [How to Test Your Code](#how-to-test-your-code)

Your program should behave per the examples below.

``` highlight
$ ./scrabble
Player 1: Question?
Player 2: Question!
Tie!
```

``` highlight
$ ./scrabble
Player 1: Oh,
Player 2: hai!
Player 2 wins!
```

``` highlight
$ ./scrabble
Player 1: COMPUTER
Player 2: science
Player 1 wins!
```

``` highlight
$ ./scrabble
Player 1: Scrabble
Player 2: wiNNeR
Player 1 wins!
```

Execute the below to evaluate the correctness of your code using
`check50`. But be sure to compile and test it yourself as well!

``` highlight
check50 cs50/labs/2023/x/scrabble
```

Execute the below to evaluate the style of your code using `style50`.

``` highlight
style50 scrabble.c
```

## [How to Submit](#how-to-submit)

In your terminal, execute the below to submit your work.

``` highlight
submit50 cs50/labs/2023/x/scrabble
```
