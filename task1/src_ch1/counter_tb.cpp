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
    top->en = 0;

    // variables
    int stop = 9; // stop num
    int itv = 0; // stop interval
    
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
        if ((top->count == stop) && (itv < 3)) {
            top->en = false;
            itv++;
        }
        else {
            top->en = true;
        }

        if (Verilated::gotFinish()) exit(0);
    }

    // close file & exit
    tfp->close();
    exit(0);
}