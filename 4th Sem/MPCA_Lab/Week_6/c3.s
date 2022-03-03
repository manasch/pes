.data
	num: .word 0x12345678
	odd: .asciz "ODD PARITY"
	even: .asciz "EVEN PARITY"

.text
	ldr r0, =num
	mov r3, #0 ; count register
	ldr r1, [r0]

	mov r2, #0 ; count number of 1's

	l2:
		movs r1, r1, lsr #1
		bcs l1
		add r3, r3, #1

	l3:
		cmp r3, #32
		bne l2
		cmp r2, #1 ; checking for odd or even number of 1's
		bne l4
		b l5

	l1:
		add r2, r2, #1
		b l3

	l4:
		ldr r0, =odd
		swi 0x02
		swi 0x11

	l5:
		ldr r0, =even
		swi 0x02
		swi 0x11

.end