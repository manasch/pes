.data
    array: .word 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150
    key: .word 50
    success: .asciz "Successful Search"
    unsuccess: .asciz "Unsuccessful Search"

.text
    ldr r1, =array
    mov r2, #0 ; value loaded from the array
    mov r3, #0 ; start
    mov r4, #14 ; end (n - 1) if array has n elements
    mov r5, #0 ; mid
    mov r6, #0 ; offset
    ldr r9, =key ; key address
    ldr r7, [r9] ; key
    mov r8, #0 ; flag

    binary_search:
        cmp r3, r4 ; start <= end
        bgt end

        sub r5, r4, r3 ; mid = start + (end - start) / 2
        add r5, r3, r5, lsr #1
        mov r6, r5, lsl #2 ; finding the offset from the starting index
        ldr r2, [r1, r6] ; loading the mid indexed value in the array

        cmp r7, r2 ; compares key and mid
        moveq r8, #1 ; if key == arr[mid] flag = 1
        beq end

        movlt r4, r5 ; if (key < arr[mid]) end = mid
        sublt r4, r4, #1 ; end = end - 1 (effectively end = mid - 1)
        movgt r3, r5 ; else if (key > arr[mid]) start = mid
        addgt r3, r3, #1 ;  start = start + 1 (effectively start = mid + 1)

        b binary_search
    
    end:
        cmp r8, #1
        ldreq r0, =success
        ldrne r0, =unsuccess

        swi 0x02
        swi 0x011

.end
