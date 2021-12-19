module fulladd (input wire a, b, cin, output wire sum, cout);
assign sum = (a ^ b) ^ cin;
assign cout = (a & b) | (b & cin) | (a & cin);
endmodule
