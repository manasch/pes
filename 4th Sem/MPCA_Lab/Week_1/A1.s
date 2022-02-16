@ Write an ALP using ARM instruction set to check if a number stored in a register is even or odd

MOV R1, #5
AND R2, R1, #1

CMP R2, #1
BEQ ODD
MOV R0, #0
B END

ODD:
	MOV R0, #0XFF
	B END

END:
	SWI 0X011
