# include <stdio.h>
# include <unistd.h>
# include <string.h>

size_t	ft_strlen(const char *s); //Declaramos la funcion de assembly
char	*ft_strcpy(char *dest, const char *src);
int		strcmp(const char *s1, const char *s2);

int main()
{
		printf("\n========== TEST LIBASM ==========\n\n");

	/*======= STRLEN ======*/
	const char *s = "HOLA";
	printf ("\n------STRLEN------\n");
	printf ("\nOriginal: %zu\n", strlen(s));
	printf ("\nft      : %zu\n", ft_strlen(s));

	printf ("\n------STRCPY------\n");
	char dst1[100];
	char dst2[100];

	ft_strcpy(dst1, s);
	ft_strcpy(dst2, s);

   printf("src     : \"%s\"\n", s);
    printf("libc    : \"%s\"\n", dst1);
    printf("ft      : \"%s\"\n\n", dst2);
	return 0;
}
