; Write a program in arm7tdmi-isa to find the trace of a square matrix of order n

.text
	ldr r0, =a
	mov r1, #0 ; i
	mov r2, #0 ; j
	mov r3, #3 ; number of elements in a row
	mov r4, #0 ; trace result
	ldr r7, =trace

	loop:
		

		mla r5, r3, r1, r2 ; 3 * i + j
		mov r5, r5, lsl #2 ; to get the location for matrix 'a'
		ldr r6, [r0, r5] ; accessing it like a[i][j]
		cmp r1, r2 ; if i == j, then add to trace
		addeq r4, r4, r6 ; trace += a[i][j]
		add r2, r2, #1 ; increment j
		cmp r2, #3
		bne loop

		mov r2, #0 ; reset j
		add r1, r1, #1 ; increment i
		cmp r1, #3
		bne loop

		str r4, [r7]
		swi 0x011

.data
	a: .word 9, 8, 7, 6, 5, 4, 3, 2, 1
	trace: .word 0

.end
