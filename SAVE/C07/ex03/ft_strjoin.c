/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parkjoungwan <whddhs6645@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 22:12:08 by parkjoung         #+#    #+#             */
/*   Updated: 2020/11/02 01:17:07 by parkjoung        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int	result;

	result = 0;
	while (*str)
	{
		result++;
		str++;
	}
	return (result);
}

int		ft_strslen(char **strs, int size, char *sep)
{
	int	index;
	int	seplen;
	int	result;

	result = 0;
	index = 0;
	seplen = ft_strlen(sep) * (size - 1);
	while (index < size)
	{
		result += ft_strlen(strs[index++]);
	}
	result += seplen;
	return (result);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		index_1;
	int		index_2;
	int		index_3;
	int		index_s;
	char	*result;

	index_1 = 0;
	index_2 = 0;
	index_3 = 0;
	index_s = 0;
	result = (char *)malloc(sizeof(char) * ft_strslen(strs, size, sep) + 1);
	result[ft_strslen(strs, size, sep)] = '\0';
	while (index_1 < size)
	{
		while (index_2 < ft_strlen(strs[index_1]))
			result[index_3++] = strs[index_1][index_2++];
		while (index_s < ft_strlen(sep) && index_1 != size - 1)
			result[index_3++] = sep[index_s++];
		index_2 = 0;
		index_s = 0;
		index_1++;
	}
	return (result);
}
