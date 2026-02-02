section .text	;Le dice al ensamblador "todo lo que sigue es codigo que se va a ejecutar"
	global ft_strlen	;Esto que ft_strlen sea visible fuera de este archivo

ft_strlen:	;El nombre de la funcion
	mov rax, 0 ;i = 0

loop:	;es como un while
	mov dl, [rdi]	;copia cada '[rdi]' en 'dl', [rdi](es 'H'), si fuera "rdi" -> seria 'HOLA'
	cmp dl, 0	;compara 'dl' con 0 y si es 0, va directamente a "je end"
	je end	;si confirma que es '\0', va directo al end
	inc rax	;incrementa 1 el rax, (i++)
	inc rdi	;incrementamos 1 el rdi que vendria siendo ahora 'O', que seria la siguiente posicion de memoria de la string en este caso 'L'
	jmp loop	;vuelve al inicio del loop, para continuar con el siguiente byte

end:	;es el final
	ret	;Siempre retorna el valor del rax
