@ Write an ALP to compare the value R0 and R1 , add if R0 = R1, else subtract

MOV R0, #5
MOV R1, #3

CMP R0, R1
BEQ C1
SUB R2, R0, R1
B C3

C1:
	ADD R2, R0, R1
	B C3

C3:
	SWI 0X011