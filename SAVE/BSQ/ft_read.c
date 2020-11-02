#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int		g_row_len;
int		g_col_len;
char	g_empty_cha;
char	g_block_cha;
char	g_box_cha;

char	**ft_split(char *str, char *charset);

int		ft_atoi(char *str);

char	*ft_open_file(char *file_name)
{
	int		fd;
	int		len;
	int		index;
	char	*one;
	char	**result;
	char	a;
	
	index = 0;
	len = 0;
	fd = open(file_name, O_RDONLY);
	while(read(fd, &a, 1))
		len++;
	one = (char *)malloc(sizeof(char) * len);
	read(fd, one, len);
	close(fd);
	while (one[index++] != '\n');
	g_box_cha = one[index - 2];
	g_block_cha = one[index - 3];
	g_empty_cha = one[index - 4];
	result = ft_split(one + index, "\n");
	one[index - 4] = '\0';
	g_row_len = ft_atoi(one);
	g_col_len = (len - index) / g_row_len;
	return (result);
}
