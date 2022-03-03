; Write a program in ARM7TDMI-ISA to multiply 2 matrices of order3. 
; i.e., implement c[i][j]=c[i][j] x a[i][j] x b[i][j].
; 	a.  Use MLA instruction
;   b.  Use MUL instruction

; MUL

.text
	ldr r0, =a
	ldr r1, =b
	ldr r2, =c
	mov r3, #0 ; i
	mov r4, #0 ; j
	mov r5, #0 ; k
	mov r6, #3 ; number of elements in a row

	loop:
		mul r7, r6, r3
		add r7, r7, r4
		mov r7, r7, lsl #2
		mul r8, r6, r3
		add r8, r8, r5
		mov r8, r8, lsl #2
		mul r9, r6, r5
		add r9, r9, r4
		mov r9, r9, lsl #2

		mov r10, r7
		ldr r7, [r2, r7]
		ldr r8, [r0, r8]
		ldr r9, [r1, r9]
		mul r11, r8, r9
		add r11, r11, r7
		str r11, [r2, r10]
		add r5, r5, #1
		cmp r5, #3
		bne loop

		mov r5, #0 ; reset k
		add r4, r4, #1 ; increment j
		cmp r4, #3
		bne loop

		mov r4, #0
		mov r5, #0
		add r3, r3, #1
		cmp r3, #3
		bne loop

		swi 0x011

.data
	a:.word 1, 2, 3, 4, 5, 6, 7, 8, 9
	b:.word 1, 2, 3, 4, 5, 6, 7, 8, 9
	c:.word 0, 0, 0, 0, 0, 0, 0, 0, 0

.end
