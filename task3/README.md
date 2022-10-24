# Task 3 Log

## Task

**Basic Info**

* Date: 24/10/2022
* Author: Samuel Wang
* Objective: 
    * Create a counter whose value can be set with the rotary switch. (Completed)
    * Create a counter whose value can be increment with each click of the button (independant of clock cycle). (Completed)

> Note 1: Each clock cycle is configured to be 2ms on the vBuddy.

**Result**

Both moditfication was succesful and simulated correctly on the 7-segment display of the vBuddy. 

Counter with set value was modified with adding a new `par` parameter which reads in the value on the vBuddy rotary switch. The count is overwritten when `en` is 1 with the value of `par`. See `counter_set.sv` file.

Counter with single-step increment was done with the original counter. The `en` was set to `vbdFlag()` with the one-shot behavior enabled. When clicked, `en` will be 1 and `count` would increment. Immediately afterwards `vbdFlag()` will be set to 0 and so will `en` which stops the increment of `count`. See `counter_tb_single.cpp` testbench file.