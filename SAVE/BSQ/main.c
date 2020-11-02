#include <stdio.h>

char *ft_open_file(char *file_name);

int main(int argc, char **argv)
{
	if (argc == 2)
		ft_open_file(argv[1]);
}
