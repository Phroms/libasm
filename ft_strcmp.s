global ft_strcmp
    section .text

ft_strcmp:
    xor rax, rax         ; clear rax (will hold return value)
    xor rcx, rcx         ; i = 0

.loop:
    mov al, [rdi + rcx]  ; al = s1[i]
    mov bl, [rsi + rcx]  ; bl = s2[i]
    cmp al, bl
    jne .done            ; if not equal, jump
    test al, al          ; check if al == 0
    je .ret              ; both are '\0', strings equal
    inc rcx              ; i++
    jmp .loop

.done:
    sub al, bl           ; al = s1[i] - s2[i]
    movsx rax, al        ; sign-extend byte result into rax
    ret

.ret:
    xor rax, rax         ; return 0
    ret
