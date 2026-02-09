global ft_strcmp
	section .text

ft_strcmp:
	mov rax, 0

loop:
	cmp dl, [rax, rdi]
	cmp dl, 0
	je end
	inc rax
	inc rdi
	jmp loop

end:
	ret
