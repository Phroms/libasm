#include <stddef.h>
# include <stdio.h>

extern size_t ft_strlen(const char *s); // Declaramos la funcion de assembly

int main()
{
	const char *str = "HOLA";
	size_t len = ft_strlen(str);
	printf ("\nLongitud de '%s' = %zu\n\n", str, len);
	return 0;
}
