.data
	a: .word 0, 0, 0, 0, 0, 0, 0, 0, 0


.text
	ldr r1, =a
	mov r2, #0 ; row -> i
	mov r3, #0 ; col -> j

	mov r4, #3 ; no of elements in each row
	mov r5, #4 ; loc x 4
	mov r6, #5 ; diagonal elements value

	l2:
		cmp r2, r3
		beq loop

	l1:
		add r3, r3, #1
		cmp r3, #3
		bne l2
		mov r3, #0 ; reinitializing j
		add r2, r2, #1
		cmp r2, #3
		bne l2
		swi 0x11

	loop:
		mla r7, r2, r4, r3 ; r7 = r2 * r4 + r3
		mul r7, r5, r7
		str r6, [r1, r7]
		b l1

.end