.data
	a: .word 10, -5, -6, 12, -3, 8, -15, 20, 18, -25
	sum: .word 0

.text
	ldr r0, =a
	ldr r1, =sum
	mov r2, #0 @ intermediary
	mov r3, #0 @ count
	bl sumpositive
	str r2, [r1]
	swi 0x11

	sumpositive:
		ldr r4, [r0], #4
		movs r4, r4 @ moving the content back to the same location to set the condition flags
		bmi l3

		add r2, r2, r4 @ only adds when the number is positive

	l3:
		add r3, r3, #1 @ incrementing count
		cmp r3, #10
		bne sumpositive
		mov pc, lr

.end
