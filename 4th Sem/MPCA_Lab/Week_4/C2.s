.TEXT
	MOV R0, #3
	MOV R1, #5
	BL ADDITION
	ADD R3, R2, R2
	SWI 0X011


ADDITION:
	ADD R2, R0, R1
	MOV PC, LR ; MOVING PC ADDRESS BACK LR or R14
	; OR BX LR WHERE X STANDS FOR RETURN, BRANCH AND RETURN
.END