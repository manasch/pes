; DISPLAY A STRING ON THE STRING ON THE SCREEN CHARACTER WISE

.DATA
	; ASSEMBLER DIRECTIVE TO STORE CHARACTER ASCIZ MESSAGE IN DOUBLE QUOTES
	MSG: .ASCIZ "HELLO WORLD"


.TEXT
	LDR R0, =MSG
	SWI 0X02

	SWI 0X011