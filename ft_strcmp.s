global ft_strcmp
    section .text

ft_strcmp:
.loop:
    mov al, [rdi]      
    mov dl, [rsi]       ; Usamos dl en lugar de bl

    cmp al, dl
    jne .diff

    cmp al, 0
    je .equal

    inc rdi
    inc rsi
    jmp .loop

.diff:
    movzx eax, al
    movzx edx, dl       ; Usamos edx
    sub eax, edx        ; Resultado: s1[i] - s2[i]
    ret

.equal:
    xor eax, eax
    ret
