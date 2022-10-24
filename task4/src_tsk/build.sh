#!/bin/sh

# cleanup
rm -rf obj_dir
rm -f counter.vcd

# run verilator translation
verilator --cc counter.sv
verilator --cc bin2bcd.sv
verilator --Wall --cc --trace top.sv --exe top_tb.cpp

# build verilator translation
make -j -C obj_dir/ -f Vtop.mk Vtop
