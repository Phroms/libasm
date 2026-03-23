global ft_strdup

extern	malloc
extern	ft_strlen
extern	ft_strcpy

section .text

ft_strdup:
		push rdi		;guardar s
		
		call ft_strlen	;rax = longitud
		inc rax

		mov rdi, rax	;argumento para malloc
		call malloc		;rax = puntero

		cmp rax, 0
		je .fail

		mov rdi, rax	;dest
		pop rsi			;src original
		call ft_strcpy

		ret

.fail:
		pop rdi			;limpiar stack
		xor rax, rax	;return NULL
		ret
