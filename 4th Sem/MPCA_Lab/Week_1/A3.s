@ Based on the value of the number in R0, if R0 = 0, then store 1 in R1, if R0 = +ve then store 2 in R2 else IF RI = -ve, then store 3
MOV R0, #-4
MOV R1, #0

CMP R0, #0
BEQ C1
BLT C2

MOV R1, #2
B C3

C1:
	MOV R1, #1
	B C3

C2:
	MOV R1, #3
	B C3

C3:
	SWI 0X011
