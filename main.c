# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>

size_t	ft_strlen(const char *s); //Declaramos la funcion de assembly
char	*ft_strcpy(char *dest, const char *src);
int		ft_strcmp(const char *s1, const char *s2);
ssize_t	ft_write(int fd, const void *buf, size_t count);
ssize_t	ft_read(int fd, void *buf, size_t count);
char	*ft_strdup(const char *s);

int main()
{
		printf("\n\033[92m========== TEST LIBASM ==========\033[0m\n");

	/*======= STRLEN ======*/
	const char *s = "HOLA COMO ESTAS";
	//const char *str = "PAPAYA";
	printf ("\n\033[94m------STRLEN------\033[0m\n");
	printf ("\nOriginal: %zu\n", strlen(s));
	printf ("ft      : %zu\n", ft_strlen(s));
	
	/*======= STRCPY ======*/
	printf ("\n\033[94m------STRCPY------\033[0m\n");
	char dst1[100];
	char dst2[100];

	strcpy(dst1, s);
	ft_strcpy(dst2, s);

	printf("src     : \"%s\"\n", s);
    printf("libc    : \"%s\"\n", dst1);
    printf("ft      : \"%s\"\n", dst2);

	/*======= STRCMP ======*/
	printf("\n\033[94m------STRCMP------\033[0m\n");

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

	/*====== WRITE ======*/

	printf("\n\033[94m------WRITE------\033[0m\n");

	char *msg = "Hola desde write\n";

	ssize_t libc_ret = write(1, msg, strlen(msg));
	ssize_t ft_ret = ft_write(1, msg, strlen(msg));

	printf("\nlibc write retorno: %zd\n", libc_ret);
	printf("ft_write retorno  : %zd\n", ft_ret);

	printf("\n\033[91m------WRITE ERROR TEST------\033[0m\n");

	ssize_t libc_err = write(-1, msg, strlen(msg));
	ssize_t ft_err = ft_write(-1, msg, strlen(msg));

	printf("libc write error: %zd\n", libc_err);
	printf("ft_write error : %zd\n", ft_err);

	/*====== READ ======*/

	printf("\n\033[94m------READ------\033[0m\n");

	char buf1[100];
	char buf2[100];

	printf("\nEscribe algo (libc read):\n");
	ssize_t libc_r = read(0, buf1, 20);

	printf("\nEscribe algo (ft_read):\n");
	ssize_t ft_r = ft_read(0, buf2, 20);

	if (libc_r > 0)
    	buf1[libc_r] = '\0';
	if (ft_r > 0)
    	buf2[ft_r] = '\0';

	printf("\nlibc read retorno: %zd\n", libc_r);
	printf("ft_read retorno  : %zd\n", ft_r);

	printf("\nlibc buf: %s", buf1);
	printf("ft   buf: %s\n", buf2);

	printf("\n\033[94m------STRDUP------\033[0m\n");

	char *original = "Hola mundo";
	char *libc_dup = strdup(original);
	char *ft_dup = ft_strdup(original);
	if (!ft_dup)
	{
		free(libc_dup);
		printf("epaaaa\n");
		exit(1);
	}

	printf("original : %s\n", original);
	printf("libc     : %s\n", libc_dup);
	printf("ft       : %s\n", ft_dup);

	free(libc_dup);
	free(ft_dup);
}
