.data
	string: .asciz "My name is Bond."
	letter: .asciz "n"

.text
	ldr r1, =letter
	ldrb r0, [r1]
	mov r2, r0 ; holds 'n' to compare
	mov r3, #0 ; count

	ldr r1, =string
	loop:
		ldrb r0, [r1], #1
		cmp r0, r2
		addeq r3, r3, #1
		cmp r0, #0
		bne loop

	swi 0x011
