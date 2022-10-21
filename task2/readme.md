# Task 2 Log

## Task

**Basic Info**

* Date: 21/10/2022
* Author: Samuel Wang
* Objective:
    * Connect laptop to vBuddy. (Completed)
    * Test switching counter enable with rotary switch push button. (Completed)
    * Test two displays, 7-segment display and plot, on vBuddy. (Completed)
* Others:
    * Modified `build.sh` and added `run.sh` for quick access to commands.
    * Added `.gitignore` to avoid pushing large binary files.
    * Logged process in `README.md`.

**Result**

vBuddy and testbench behaved as expected. Observations:

* 7-segment Display
    * Numbers displayed in hexadecimal.
    * When pushed, numbers increase.
    * When pushed again, numbers stay static until stop.
    * See Figure 1 below.
    
* Plot
    * Flat line until button pushed.
    * After pushed, line goes up in slope 1.
    * Fits the description of adding 1 per cycle.
    * See Figure 2 below.

<figure>
    <img src="./docs/task2-sev-seg.png" style="width: 75%">
    <figcaption>Figure 1: vBuddy 7-Segment Display</figcaption>
</figure>

<figure>
    <img src="./docs/task2-plot.png" style="width: 75%">
    <figcaption>Figure 2: vBuddy Plot Display</figcaption>
</figure>

> Note 1: `>>` is the bitwise shift operator. E.g. `num >> 4` is num right shift by 4 digits.

> Note 2: `&` is the bitwise AND operator. E.g. `(num) & 0xF` gives you the last four digits, as `0xF` is `0000 1111`.


## Test Yourself Challenge

To-Be-Done