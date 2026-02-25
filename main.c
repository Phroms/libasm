# include <stdio.h>
# include <unistd.h>
# include <string.h>

size_t	ft_strlen(const char *s); //Declaramos la funcion de assembly
char	*ft_strcpy(char *dest, const char *src);
int ft_strcmp(const char *s1, const char *s2);

int main()
{
		printf("\n========== TEST LIBASM ==========\n\n");

	/*======= STRLEN ======*/
	const char *s = "HOLA COMO ESTAS";
	//const char *str = "PAPAYA";
	printf ("\n------STRLEN------\n");
	printf ("\nOriginal: %zu\n", strlen(s));
	printf ("\nft      : %zu\n", ft_strlen(s));
	
	/*======= STRCPY ======*/
	printf ("\n------STRCPY------\n");
	char dst1[100];
	char dst2[100];

	ft_strcpy(dst1, s);
	ft_strcpy(dst2, s);

	printf("src     : \"%s\"\n", s);
    printf("libc    : \"%s\"\n", dst1);
    printf("ft      : \"%s\"\n\n", dst2);

	/*======= STRCMP ======*/
	printf("\n------STRCMP------\n");

	printf("\nIguales:\n");
	printf("libc : %d\n", strcmp("hola", "hola"));
	printf("ft   : %d\n", ft_strcmp("hola", "hola"));

	printf("\nMenor:\n");
	printf("libc : %d\n", strcmp("abc", "abd"));
	printf("ft   : %d\n", ft_strcmp("abc", "abd"));

	printf("\nMayor:\n");
	printf("libc : %d\n", strcmp("zoo", "bar"));
	printf("ft   : %d\n", ft_strcmp("zoo", "bar"));

	printf("\nCon vacíos:\n");
	printf("libc : %d\n", strcmp("", ""));
	printf("ft   : %d\n", ft_strcmp("", ""));

	printf("\nPrefijo:\n");
	printf("libc : %d\n", strcmp("hola", "holanda"));
	printf("ft   : %d\n", ft_strcmp("hola", "holanda"));
	return 0;
}
