module TB;
reg aa,bb;
wire ss,cy;
halfadd add1(.a(aa), .b(bb), .s(ss), .cout(cy));
initial
begin
$dumpfile("dump.vcd");
$dumpvars(0, TB);
end

initial begin $monitor(aa,bb,ss,cy);
aa = 1'b0;
bb = 1'b0;
#5
aa = 1'b0;
bb = 1'b1;
#5
aa = 1'b1;
bb = 1'b0;
#5
aa = 1'b1;
bb = 1'b1;
#5
aa = 1'b0;
bb = 1'b0;
end
endmodule