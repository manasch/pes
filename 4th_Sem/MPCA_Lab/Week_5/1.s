; Fibonacci Series
.DATA
    A: .WORD 0, 0, 0, 0, 0, 0, 0, 0, 0, 0


.TEXT
    LDR R3, =A
    MOV R0, #0 ; 1ST
    MOV R1, #1 ; 2ND
    MOV R4, #1 ; COUNT

    LOOP:
        ADD R2, R0, R1
        STR R2, [R3], #4 ; STORE
        MOV R0, R1 ; ASSIGN
        MOV R1, R2
        ADD R4, R4, #1
        CMP R4, #11
        BNE LOOP
    
    SWI 0X011

