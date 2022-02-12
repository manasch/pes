module halfadd (input wire a, b, output wire s, cout);
assign s = (a ^ b);
assign cout = (a & b);
endmodule
