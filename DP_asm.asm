; PANGAN, YA || DELOS REYES, CJ
section .text
global dot_product_kernel

dot_product_kernel:
    ; Parameters:
    ; rcx = n -> number of elements sa vector
    ; rdx = arr1 -> pointer to vec1
    ; r8  = arr2 -> pointer to vec2
    ; r9  = sdot -> pointer to scalar result

    xorps xmm0, xmm0      
    mov r10, rcx
    xor r11, r11

.loop:
    cmp r11, r10
    jge .done                

    movsd xmm1, [rdx + r11*8] 
    movsd xmm2, [r8 + r11*8]  
    mulsd xmm1, xmm2          
    addsd xmm0, xmm1          
    inc r11
    jmp .loop                

.done:
    movsd [r9], xmm0  
    ret