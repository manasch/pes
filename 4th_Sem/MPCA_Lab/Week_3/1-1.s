; Write a program in ARM7TDMI-ISA to find GCD of two numbers.
;	a) Assume operands to be in the CPU registers
;	b) Assume operands in the memory locations

; Operands in CPU registers

.TEXT
	MOV R0, #10
	MOV R1, #15

	GCD:
		CMP R0, R1
		BEQ L1
		BLT LOOP
		SUB R0, R0, R1
		B GCD

	L1:
		MOV R2, R0 ; OR MOV R2, R1
		B E

	LOOP:
		SUB R1, R1, R0
		B GCD

	E:
		SWI 0X011
