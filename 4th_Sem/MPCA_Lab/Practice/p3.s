.text
	ldr r4, =a
	ldr r5, =b
	;ldr r1, [r4], #4
	;ldr r2, [r4], #4
	;ldr r3, [r4], #4
	ldmia r4!, {r1, r2, r3}
	stmia r5, {r1, r2, r3}
	swi 0x11

.data
	a: .word 10, 20, 30, 40, 50
	b: .word
