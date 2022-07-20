.TEXT ; CODE SEGMENT
	LDR R1,=A
	LDR R2,=B
	LDR R6,=C

	LDR R3,[R1] ; [] CONTENT AT ADDRESS
	LDR R4,[R2]

	ADD R5, R3, R4

	STR R5, [R6]
	SWI 0X011 ; LOGICAL END


.DATA ; DATA SEGMENT
	A: .WORD 0X12345678 ; .WORD (ASSEMBLER DIRECTIVE) INDICATES THAT IT'S A WORD AS WORD IS 32 BIT IN LENGTH
	B: .WORD 0X11111111

	; LDR -> LOAD INSTRUCTION
	C: .WORD 0X00000000
		; PHYSICAL END