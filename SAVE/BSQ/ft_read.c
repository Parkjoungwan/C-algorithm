/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parkjoungwan <whddhs6645@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 00:09:02 by parkjoung         #+#    #+#             */
/*   Updated: 2020/11/04 01:15:46 by parkjoung        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	test_print(char **result)
{
	int index;

	index = 0;
	while(index < g_row_len)
		printf("%s\n", result[index]);
}

char	**ft_send_2dm(char *one, int len)
{
	int index;
	char	**result;

	index = 0;
	while (one[index] != '\n')
		index++;
	g_box_cha = one[index - 2];
	g_block_cha = one[index - 3];
	g_empty_cha = one[index - 4];
	result = ft_split(one + index, "\n");
	one[index - 4] = '\0';
	g_row_len = ft_atoi(one);
	g_col_len = (len - index) / g_row_len;
	return (result);
}

void	ft_open_file(char *file_name)
{
	int		fd;
	int		len;
	char	a;
	char	*one;

	len = 0;
	fd = open(file_name, O_RDONLY);
	while (read(fd, &a, 1))
		len++;
	close(fd);
	fd = open(file_name, O_RDONLY);
	one = (char *)malloc(sizeof(char) * len);
	read(fd, &one, len);
	printf("%d\n", len);
	printf("%d\n", one[len+1]);
	printf("%d\n", a);
	close(fd);
	//ft_send_2dm(one, len);
}
