global .text
	section ft_strcpy

	; rdi = dst;
	; rsi = src;
	; return = rax;

ft_strcpy:
	mov rax, rdi ;Guardamos dst para tener el valor

loop:
	mov dl, [rsi]
	mov [rdi], dl

	inc rsi
	inc rdi

	cmp dl, 0
	je loop

	ret
