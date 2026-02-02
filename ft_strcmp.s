global .text
	section ft_strcmp

ft_strcmp:
	mov rax, 0

loop:
	cmp dl, [rax, rdi]
	cpm dl, 0
	je end
	inc rax
	inc rdi
	jmp loop

end:
	ret
