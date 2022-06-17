.data
    string: .asciz "My name is Bond"
    pattern: .asciz "James"
    present: .asciz "String Present"
    absent: .asciz "String Absent"

.text
    ldr r1, =string
    mov r2, #0 ; length of string = n
    ldr r3, =pattern
    mov r4, #0 ; length of pattern = m
    mov r9, #0 ; flag = 0

    ; Finding lengths of string and pattern
    mov r5, r1 ; temp register
    ; lenfth of the string  
    len1:
        ldrb r0, [r5], #1
        cmp r0, #0
        addne r2, r2, #1
        bne len1
    
    mov r5, r3
    ; length of the pattern
    len2:
        ldrb r0, [r5], #1
        cmp r0, #0
        addne r4, r4, #1
        bne len2
    
    cmp r2, r4 ; if n < m
    blt end
    sub r5, r2, r4 ; n - m

    mov r2, #0 ; r2 is not needed anymore, so will act as the counter (i)
    stringmatch:
        cmp r2, r5 ; for (i = 0; i < n - m; i++)
        bgt end

        mov r6, #0 ; j = 0

        compare:
            cmp r6, r4 ; if j == m
            moveq r9, #1 ; flag = 1, if string present
            beq end

            add r7, r2, r6 ; i + j
            ldrb r8, [r1, r7] ; string[i + j]
            ldrb r9, [r3, r6] ; pattern[j]
            cmp r8, r9 ; if string[i + j] == pattern[j]
            addeq r6, r6, #1 ; j++
            beq compare
        
        add r2, r2, #1 ; i++
        b stringmatch
    
    end:
        cmp r9, #1
        ldreq r0, =present
        ldrne r0, =absent

        swi 0x02

    swi 0x011
.end
