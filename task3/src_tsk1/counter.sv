module counter #(
    parameter WIDTH = 8 // width of counter
)(
    input logic clk, // clock
    input logic rst, // reset
    input logic en, // enable
    input logic [WIDTH-1:0] par, // vbuddy parameter
    output logic [WIDTH-1:0] count // count output
);

always_ff @ (posedge clk)
    if (rst) count <= {WIDTH{1'b0}};
    else count <= (en ? par : count);

endmodule
