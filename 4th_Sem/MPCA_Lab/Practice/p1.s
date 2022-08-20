.text
	ldr r7, =a
	mov r1, #11
	mov r2, #10
	mov r3, #2
	stmfd sp!, {r1, r2, r3}
	bl addfun
	str r0, [r7]
	swi 0x11

	addfun:
		ldmfd sp!, {r4, r5, r6}
		add r0, r4, r5
		stmfd sp!, {r0, r6, lr}
		bl mulfun
		mov pc, lr

	mulfun:
		ldmfd sp!, {r4, r5, lr}
		mul r0, r4, r5
		mov pc, lr

.data
	a: .word 0