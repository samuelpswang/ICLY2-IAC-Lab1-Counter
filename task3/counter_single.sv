module counter #(
    parameter WIDTH = 8 // width of counter
)(
    input logic clk, // clock
    input logic rst, // reset
    input logic en, // enable
    output logic [WIDTH-1:0] count // count output
);

always_ff @ (posedge clk)
    if (rst) count <= {WIDTH{1'b0}};
    else count <= count + {{WIDTH-1{1'b0}}, en};

endmodule
