;PANGAN, YUMI ANN  || DE LOS REYES, CARL JUSTIN

;Algo ng Dot Product (Assembly Kernel):
; 1. Initialize mo yung SIMD register xmm0 to store yung result (sdot = 0.0).
; 2. Loop sa vectors A and B (for n elements):
;    - Load A[i] into xmm1.
;    - Load B[i] into xmm2.
;    - Multiply xmm1 and xmm2, storing the result sa xmm1.
;    - Add xmm1 to xmm0 to accumulate the sum.
; 3. Store the final result sa xmm0 to memory.
; 4. Return to the caller.

section .text
    global dot_product_asm

dot_product_asm:
    vxorpd xmm0, xmm0, xmm0        ; Clear xmm0 (initialize sdot to 0.0)

.loop:
    cmp rcx, 0                     ; Check if the loop counter (n) is 0
    jz .end                        ; Exit loop if done

    movsd xmm1, qword [rdi]        ; Load A[i] into xmm1
    movsd xmm2, qword [rsi]        ; Load B[i] into xmm2
    mulsd xmm1, xmm2               ; Multiply A[i] * B[i]
    addsd xmm0, xmm1               ; Add the product to xmm0 (accumulate result)

    add rdi, 8                     ; Increment pointer for A (next element)
    add rsi, 8                     ; Increment pointer for B (next element)
    dec rcx                        ; Decrement loop counter
    jmp .loop                      ; Repeat the loop

.end:
    movsd qword [rdx], xmm0        ; Store the result in memory (sdot)
    ret
