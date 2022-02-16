@ Write a program in ARM7TDMI-ISA to find the sim of N data items in the memory.
@ Store the result in the memory location
@	a) Use Pre-Indexing addressing mode
@	b) Use Post-Indexing addressing mode
@	c) Use Auto-Indexing addressing mode

@ Pre-Indexing addressing mode

.TEXT
	LDR R1, =A
	LDR R3, =SUM
	MOV R2, #0 @ Sum register
	MOV R4, #1
	MOV R5, #0

	LOOP:
		LDR R6, [R1, R5]
		ADD R2, R2, R6
		ADD R5, R5, #4
		ADD R4, R4, #1
		CMP R4, #6
		BNE LOOP

	STR R2, [R3]
	SWI 0X011

.DATA
	A: .WORD 10, 20, 30, 40, 50
	SUM: .WORD 0