.data
    a: .word 0x98761234
    sum: .word 0

.text
    ldr r0, =a
    ldr r1, [r0]
    mov r2, #15 ; Will be anded with the number to get the last digit, bin(15) = 1111
    mov r3, #0 ; sum variable

    loop:
        and r4, r1, r2 ; stores the last digit in r4
        add r3, r3, r4
        mov r1, r1, lsr #4 ; right shift the number
        cmp r1, #0
        bne loop
    
    ldr r5, =sum
    str r3, [r5]
    swi 0x011
