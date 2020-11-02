#include <stdio.h>

char *ft_convert_base(char *nbr, char *base_from, char *base_to);

int		main(void)
{
	printf("result : $%s$\n", ft_convert_base("2147483647", "0123456789", "0123456789abcdef"));
	printf("result : $%s$\n", ft_convert_base("---------7fffffff", "0123456789abcdef", "01"));
	printf("result : $%s$\n", ft_convert_base("--+--0001023a", "0123456789", "0123456789"));
	printf("result : $%s$\n", ft_convert_base("0", "0123456789", "abcdefghij"));
}
