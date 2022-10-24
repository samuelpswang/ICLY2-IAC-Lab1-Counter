#include "Vcounter.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

int main(int argc, char **argv, char **env) {
    int i;
    int clk;

    Verilated::commandArgs(argc, argv);
    
    // initiate top-level design
    Vcounter* top = new Vcounter;

    // initiate trace
    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    top->trace(tfp, 99);
    tfp->open("counter.vcd");
    
    // initiate simulation inputs
    top->clk = 1;
    top->rst = 1;
    top->en = 1;

    // variables
    int stop = 9;
    int itv = 0;
    
    // run simulation
    for (i = 0; i < 250; i++) {
        // dump data & toggle clock
        for (clk = 0; clk < 2; clk++) {
            tfp->dump(2*i+clk);
            top->clk = !top->clk;
            top->eval();
        }
        // test pattern
        top->rst = (i == 1);
        if (Verilated::gotFinish()) exit(0);
    }

    // close file & exit
    tfp->close();
    exit(0);
}