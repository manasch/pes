module fulladd (input wire i0, i1, cin, output wire sum, cout);
	wire t0, t1, t2;
	xor3 xor3_0 (i0, i1, cin, sum);
	and2 and2_0 (i0, i1, t0);
	and2 and2_1 (i1, cin, t1);
	and2 and2_2 (cin, i1, t2);
	or3 or3_0 (t0, t1, t2, cout);
endmodule

module addsub (input wire i0, i1, asb, cin, output wire sd, cout); //asb: addsubbit, sd: sumdifference
	wire t;
	xor2 xor2_0 (i1, asb, t);
	fulladd fa_0 (i0, t, cin, sd, cout);
endmodule

module alu_slice_io (input wire [1:0]op, input wire i0, i1, cin, output wire cout, o);
	wire t0, t1, t2, sd;
	
	//t0: output of and
	//t1: output of or
	//t2: output of mux1
	//sd: sumdifference output
	
	addsub addsub_0 (i0, i1, op[0], cin, sd, cout);
	and2 and2_3 (i1, i0, t0);
	or2 or2_0 (i0, i1, t1);
	mux2 mux2_0 (t0, t1, op[0], t2);
	mux2 mux2_1 (t2, sd, op[1], o);
endmodule

module alu (input wire [1:0] op, input wire [15:0] i0, i1,
    output wire [15:0] o, output wire cout);
	wire [0:14]c;
	
	alu_slice_io a0 (op, i0[0], i1[0], op[0], c[0], o[0]);
	alu_slice_io a1 (op, i0[1], i1[1], c[0], c[1], o[1]);
	alu_slice_io a2 (op, i0[2], i1[2], c[1], c[2], o[2]);
	alu_slice_io a3 (op, i0[3], i1[3], c[2], c[3], o[3]);
	alu_slice_io a4 (op, i0[4], i1[4], c[3], c[4], o[4]);
	alu_slice_io a5 (op, i0[5], i1[5], c[4], c[5], o[5]);
	alu_slice_io a6 (op, i0[6], i1[6], c[5], c[6], o[6]);
	alu_slice_io a7 (op, i0[7], i1[7], c[6], c[7], o[7]);
	alu_slice_io a8 (op, i0[8], i1[8], c[7], c[8], o[8]);
	alu_slice_io a9 (op, i0[9], i1[9], c[8], c[9], o[9]);
	alu_slice_io a10 (op, i0[10], i1[10], c[9], c[10], o[10]);
	alu_slice_io a11 (op, i0[11], i1[11], c[10], c[11], o[11]);
	alu_slice_io a12 (op, i0[12], i1[12], c[11], c[12], o[12]);
	alu_slice_io a13 (op, i0[13], i1[13], c[12], c[13], o[13]);
	alu_slice_io a14 (op, i0[14], i1[14], c[13], c[14], o[14]);
	alu_slice_io a15 (op, i0[15], i1[15], c[14], cout, o[15]);
	
endmodule
