.DATA
	A: .WORD 5
	B: .WORD 7
	C: .WORD 6
	D: .WORD 6
	E: .WORD 0

.TEXT
	LDR R0, =A
	LDR R1, =B
	LDR R2, =C
	LDR R3, =D
	LDR R4, =E
	LDR R5, [R0] ;A
	LDR R6, [R1] ;B
	LDR R7, [R2] ;C
	LDR R8, [R3] ;D

	CMP R5, R6
	BEQ C1
	CMP R6, R7
	BEQ C2
	MUL R9, R5, R6
	STR R9, [R4]
	B C3

	C1:
		ADD R9, R5, R6
		STR R9, [R2]
		B C3

	C2:
		SUB R9, R6, R7
		STR R9, [R3]
		B C3

	C3:
		SWI 0X011
