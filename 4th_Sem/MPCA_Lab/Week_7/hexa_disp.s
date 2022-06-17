.text 
.global _start
begin:
    mov r0, #0 
    mov r2, #0
again:
    swi 0x202 ; check whether cmp ro, #1 ; black button pressed or not
    beq loop1 
    b again

loop1:
    mov r5, #19 
    ldr r1,=zero

back1:
    ldrb r0, [r1] 
    swi 0x200 ; Set 8 segment display to light up 
    bl delay 
    add r1,r1,#1 
    sub r5, r5,#1 
    cmp r5, #0 
    bne back1 
    b again

delay:
    mov r4, #64000

loop3:
    sub r4, r4, #1 
    cmp r4, #0 
    bge loop3 
    mov pc, lr

.data
zero: .byte 011101101 
one: .byte 0b01100000 
two: .byte 0b11001110 
three: .byte 0511111010 
four: .byte 0b01110011 
five: .byte 0b10101011 
six: .byte 0b10101111 
seven: .byte 0b11100000 
eight: .byte 0b11101111 
nine: .byte 0b11100011 
A: .byte 0b11100111 
B: .byte 0b00101111 
C: .byte 0b10001101 
D: .byte 0b01101110
E: .byte 0b10001111 
F: .byte 0b10000111 
p: .byte 0b11000111 
e: .byte 0b10001111 
s: .byte 0b10101011