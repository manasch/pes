; Write a program in ARM7TDMI-ISA to find the sum of N data items at alternate [odd or even positions] locations in the memoty.
; Store the results in the memory location.
;	a) Use Pre-Indexing addressing mode
;	b) Use Post-Indexing addressing mode
;	c) Use Auto-Indexing addressing mode

; Post-Indexing

.text
	ldr r0, =a
	ldr r1, =sum
	mov r2, #0 ; sum variable
	mov r3, #0 ; count

	loop:
		ldr r5, [r0], #8
		add r2, r2, r5
		add r3, r3, #1 ; increment count
		cmp r3, #5
		bne loop

	str r2, [r1]
	swi 0x011

.data
	a: .word 10, 20, 30, 40, 50, 60, 70, 80, 90, 100
	sum: .word 0
