/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parkjoungwan <whddhs6645@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 01:32:23 by parkjoung         #+#    #+#             */
/*   Updated: 2020/11/03 23:57:50 by parkjoung        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_strcpy(char *dest, char *start, char *end)
{
	while (start < end)
	{
		*dest = *start;
		dest++;
		start++;
	}
	*dest = '\0';
}

int		ft_isit_set(char c, char *set)
{
	int index;

	index = 0;
	while (set[index])
	{
		if (set[index] == c)
			return (1);
		index++;
	}
	return (0);
}

int		ft_count(char *str, char *set)
{
	int	result;
	int	index;

	result = 0;
	index = 0;
	while (str[index])
	{
		if (!ft_isit_set(str[index], set))
		{
			result++;
			while (str[index] && !ft_isit_set(str[index], set))
				index++;
		}
		index++;
	}
	return (result);
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	char	*temp;
	int		index;

	index = 0;
	result = (char**)malloc(sizeof(char *) * (ft_count(str, charset) + 1));
	while (*str)
	{
		if (!ft_isit_set(*str, charset))
		{
			temp = str;
			while (*str && !ft_isit_set(*str, charset))
				str++;
			result[index] = (char *)malloc(sizeof(char) * (str - temp + 1));
			ft_strcpy(result[index], temp, str);
			index++;
		}
		str++;
	}
	result[index] = 0;
	return (result);
}
