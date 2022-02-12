module mux4 (input wire [0:3]i, input wire j0, j1, output wire o);
wire x0, x1;

mux2 m0 (i[0], i[1], j0, x0);
mux2 m1 (i[2], i[3], j0, x1);
mux2 m2 (x0, x1, j1, o);

endmodule
