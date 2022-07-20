; WRITE A ALP TO COPY BLOCK OF CODE .WORD ADDRESSING
.DATA
	A: .WORD 100, 200, 300, 400, 500, 600, 700, 800, 900, 1000
	B: .WORD 0, 0, 0, 0, 0, 0, 0, 0, 0, 0

.TEXT
	LDR R1, =A
	LDR R2, =B

	MOV R4, #0 ; COUNT REGISTER
	LOOP:
		LDR R3, [R1]
		STR R3, [R2]
		ADD R1, R1, #4 ; UPDATING THE ARRAY INDEX
		ADD R2, R2, #4
		ADD R4, R4, #1 ; UPDATE COUNT
		CMP R4, #10
		BNE LOOP
	SWI 0x011

.END