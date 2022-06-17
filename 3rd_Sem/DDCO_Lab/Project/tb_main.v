module tb;
	reg [15:0] i; reg [3:0] shift; reg [1:0] op;
	wire [15:0] shift_left, shift_right, rotate_left, rotate_right; wire [15:0] o;

	initial begin
		$dumpfile("tb.vcd");
		$dumpvars(0, tb);
	end

	left_shift ls_0(i, shift, shift_left);
	right_shift rs_0(i, shift, shift_right);
	left_rotate lr_0(i, shift, rotate_left);
	right_rotate rr_0(i, shift, rotate_right);
	alu alu_o(.i(i), .shift(shift), .op(op), .o(o));
	initial begin
		i = 16'b1000000000000101;
		shift = 4'b0000;
		op = 2'b00;
		#5
		shift = 4'b0000;
		op = 2'b01;
		#5
		shift = 4'b0000;
		op = 2'b10;
		#5
		shift = 4'b0000;
		op = 2'b11;
		#5
		shift = 4'b0001;
		op = 2'b00;
		#5
		shift = 4'b0001;
		op = 2'b01;
		#5
		shift = 4'b0001;
		op = 2'b10;
		#5
		shift = 4'b0001;
		op = 2'b11;
		#5
		shift = 4'b0010;
		op = 2'b00;
		#5
		shift = 4'b0010;
		op = 2'b01;
		#5
		shift = 4'b0010;
		op = 2'b10;
		#5
		shift = 4'b0010;
		op = 2'b11;
		#5
		shift = 4'b0011;
		op = 2'b00;
		#5
		shift = 4'b0011;
		op = 2'b01;
		#5
		shift = 4'b0011;
		op = 2'b10;
		#5
		shift = 4'b0011;
		op = 2'b11;
		#5
		shift = 4'b0100;
		op = 2'b00;
		#5
		shift = 4'b0100;
		op = 2'b01;
		#5
		shift = 4'b0100;
		op = 2'b10;
		#5
		shift = 4'b0100;
		op = 2'b11;
		#5
		shift = 4'b0101;
		op = 2'b00;
		#5
		shift = 4'b0101;
		op = 2'b01;
		#5
		shift = 4'b0101;
		op = 2'b10;
		#5
		shift = 4'b0101;
		op = 2'b11;
		#5
		shift = 4'b0110;
		op = 2'b00;
		#5
		shift = 4'b0110;
		op = 2'b01;
		#5
		shift = 4'b0110;
		op = 2'b10;
		#5
		shift = 4'b0110;
		op = 2'b11;
		#5
		shift = 4'b0111;
		op = 2'b00;
		#5
		shift = 4'b0111;
		op = 2'b01;
		#5
		shift = 4'b0111;
		op = 2'b10;
		#5
		shift = 4'b0111;
		op = 2'b11;
		#5
		shift = 4'b1000;
		op = 2'b00;
		#5
		shift = 4'b1000;
		op = 2'b01;
		#5
		shift = 4'b1000;
		op = 2'b10;
		#5
		shift = 4'b1000;
		op = 2'b11;
		#5
		shift = 4'b1001;
		op = 2'b00;
		#5
		shift = 4'b1001;
		op = 2'b01;
		#5
		shift = 4'b1001;
		op = 2'b10;
		#5
		shift = 4'b1001;
		op = 2'b11;
		#5
		shift = 4'b1010;
		op = 2'b00;
		#5
		shift = 4'b1010;
		op = 2'b01;
		#5
		shift = 4'b1010;
		op = 2'b10;
		#5
		shift = 4'b1010;
		op = 2'b11;
		#5
		shift = 4'b1011;
		op = 2'b00;
		#5
		shift = 4'b1011;
		op = 2'b01;
		#5
		shift = 4'b1011;
		op = 2'b10;
		#5
		shift = 4'b1011;
		op = 2'b11;
		#5
		shift = 4'b1100;
		op = 2'b00;
		#5
		shift = 4'b1100;
		op = 2'b01;
		#5
		shift = 4'b1100;
		op = 2'b10;
		#5
		shift = 4'b1100;
		op = 2'b11;
		#5
		shift = 4'b1101;
		op = 2'b00;
		#5
		shift = 4'b1101;
		op = 2'b01;
		#5
		shift = 4'b1101;
		op = 2'b10;
		#5
		shift = 4'b1101;
		op = 2'b11;
		#5
		shift = 4'b1110;
		op = 2'b00;
		#5
		shift = 4'b1110;
		op = 2'b01;
		#5
		shift = 4'b1110;
		op = 2'b10;
		#5
		shift = 4'b1110;
		op = 2'b11;
		#5
		shift = 4'b1111;
		op = 2'b00;
		#5
		shift = 4'b1111;
		op = 2'b01;
		#5
		shift = 4'b1111;
		op = 2'b10;
		#5
		shift = 4'b1111;
		op = 2'b11;
		#5
		$finish;
	end
endmodule