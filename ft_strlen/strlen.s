global ft_strlen	;Esto que ft_strlen sea visible fuera de este archivo

section .text	;Le dice al ensamblador "todo lo que sigue es codigo que se va a ejecutar"

ft_strlen:
	xor rax, rax	;entender un poco mas esta linea

loop:	;es como un while
	mov dl, [rdi]	;cargas en 'al' el valor apuntado en rdi(en este caso 'H')
	cmp dl, 0	;compara 'al' con 0 y si es 0, va directamente a "je end"
	je end	;si confirma que es '\0', va directo al end
	inc rax	;incrementa 1 el rax que cuenta los caracteres de la string, osea de lo que conto 1 que era 'H', ahora contara 2 porque esta viendo 'O'
	inc rdi	;incrementamos 1 el rdi que vendria siendo ahora 'O', que seria la siguiente posicion de memoria de la string
	jmp loop	;vuelve al inicio del loop, para continuar con el siguiente byte

end:	;es el final
	ret	;retorna el valor que en este caso seria ver el valor que tiene de lo que leyo, si es 'HOLA' devuelve 4, si es 'PATATA' deveulve 6
