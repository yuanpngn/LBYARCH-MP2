section .text
global dot_product_kernel

dot_product_kernel:
    ; Parameters:
    ; rcx = n (number of elements)
    ; rdx = arr1 (pointer to vec1)
    ; r8  = arr2 (pointer to vec2)
    ; r9  = sdot (pointer to scalar result)

    ; Initialize dot product accumulator to 0.0
    xorps xmm0, xmm0          ; Clear xmm0 (this sets it to 0.0)

    ; Save n (number of elements) in r10
    mov r10, rcx

    ; Initialize index register (r11) to 0
    xor r11, r11

.loop:
    ; Compare index (r11) with n (r10)
    cmp r11, r10
    jge .done                 ; If r11 >= r10, exit loop

    ; Load elements from vec1 and vec2 into xmm1 and xmm2
    movsd xmm1, [rdx + r11*8] ; Load vec1[r11] into xmm1
    movsd xmm2, [r8 + r11*8]  ; Load vec2[r11] into xmm2

    ; Multiply the elements
    mulsd xmm1, xmm2          ; xmm1 = vec1[r11] * vec2[r11]

    ; Add the result to the dot product accumulator
    addsd xmm0, xmm1          ; dot_product += vec1[r11] * vec2[r11]

    ; Increment index (r11)
    inc r11
    jmp .loop                 ; Repeat loop

.done:
    ; Store the result of the dot product into memory (final result)
    movsd [r9], xmm0          ; Store the final result in sdot
    ret