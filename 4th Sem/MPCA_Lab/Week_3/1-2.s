; Write a program in ARM7TDMI-ISA to find GCD of two numbers.
;	a) Assume operands to be in the CPU registers
;	b) Assume operands in the memory locations

; Operands in memory locations

.TEXT
	LDR R0, =A
	LDR R1, =B
	LDR R3, [R0]
	LDR R4, [R1]

	GCD:
		CMP R3, R4
		BEQ L1
		BLT LOOP
		SUB R3, R3, R4
		B GCD

	L1:
		MOV R2, R3 ; OR MOV R2, R4
		B E

	LOOP:
		SUB R4, R4, R3
		B GCD

	E:
		SWI 0X011

.DATA
	A: .WORD 10
	B: .WORD 15