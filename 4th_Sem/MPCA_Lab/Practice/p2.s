.text
	;mov r0, #2
	;mov r1, #1
	;stmfd sp!, {r1, r0}
	;ldmfd sp!, {r5, r6}
	;ldmfa sp!, {r2, r3}
	;swi 0x011

	;ldr r4, =a
	;mov r1, #25
	;mov r2, #25
	;stmfd sp!, {r1, r2}
	;bl link
	;str r0, [r4]
	;swi 0x11

	;link:
	;	ldmfa sp!, {r4, r5}
;		add r0, r4, r5
;		mov pc, lr

.word
;	a: .word 0
.end
