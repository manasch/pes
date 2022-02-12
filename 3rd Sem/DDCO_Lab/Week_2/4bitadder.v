module fulladdR (input wire [3:0] a, b, input wire cin, output wire [3:0] s, output wire cout);
wire [2:0] c;
fulladd f_0 (a[0], b[0], cin, s[0], c[0]);
fulladd f_1 (a[1], b[1], c[0], s[1], c[1]);
fulladd f_2 (a[2], b[2], c[1], s[2], c[2]);
fulladd f_3 (a[3], b[3], c[2], s[3], cout);
endmodule
