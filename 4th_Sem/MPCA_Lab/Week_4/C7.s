; DISPLAY A STRING ON THE STRING ON THE SCREEN CHARACTER WISE

.DATA
	; ASSEMBLER DIRECTIVE TO STORE CHARACTER ASCIZ MESSAGE IN DOUBLE QUOTES
	MSG: .ASCIZ "HELLO WORLD"


.TEXT
; RESTRICTION IS THAT ADDRESS HAS TO BE STORED IN R1 ONLY, DATA HAS TO BE IN R0

	LDR R1, =MSG

	; ROUTINE TO DISPLAY CHARACTER IN R0 ONLY IS DONE BY SWI 0X00
	
	LOOP:
		LDRB R0, [R1], #1 ; POST INDEXING AND BYTE
		CMP R0, #0 ; IF NOTHING IS THERE IN R0, THEN THERE IS NO DATA TO DISPLAY
		
		SWINE 0X00 ; DISPLAY PROVIDED CONTENTS OF R0 NOT EQUAL (NE) TO 0
		BNE LOOP

	SWI 0X011