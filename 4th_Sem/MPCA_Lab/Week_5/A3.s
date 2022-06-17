; Write a program in arm7tdmi-isa to find the rowsum of a matrix.

.text
	ldr r0, =a
	ldr r1, =sum
	mov r2, #3 ; max count
	mov r3, #0 ; i
	mov r4, #0 ; j
	mov r5, #0 ; sum

	loop:
		mla r6, r2, r3, r4
		mov r6, r6, lsl #2
		ldr r7, [r0, r6]
		add r5, r5, r7
		add r4, r4, #1 ; increment j
		cmp r4, r2
		bne loop

		str r5, [r1], #4
		mov r5, #0 ; reset sum
		add r3, r3, #1 ; increment i
		mov r4, #0
		cmp r3, r2
		bne loop

		swi 0x011


.data
	a: .word 10, 20, 30, 40, 50, 60, 70, 80, 90
	sum: .word 0, 0, 0 ; for row1, row2, row3 respectively

.end
