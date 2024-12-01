; ASM - Dot Product
; LBYARCH - S11
; PANGAN, Yumi Ann
; DE LOS REYES, Carl Justin

section .text
global dot_product_kernel

dot_product_kernel:
    ; Parameters:
    ; rcx = n (number of elements)
    ; rdx = arr1 (pointer to vec1)
    ; r8  = arr2 (pointer to vec2)
    ; r9  = sdot (pointer to scalar result)
    
    xorps xmm0, xmm0        
    mov r10, rcx
    xor r11, r11

.loop:
    cmp r11, r10
    jge .done                

    ; Load elements from vec1 and vec2 into xmm1 and xmm2
    movsd xmm1, [rdx + r11*8] 
    movsd xmm2, [r8 + r11*8]  

    ; Multiply the elements
    mulsd xmm1, xmm2          

    ; Add the result to the dot product accumulator
    addsd xmm0, xmm1          

    ; Increment index (r11)
    inc r11
    jmp .loop             

.done:
    ; Store the result of the dot product into memory (final result)
    movsd [r9], xmm0      
    ret