/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parkjoungwan <whddhs6645@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 19:22:13 by parkjoung         #+#    #+#             */
/*   Updated: 2020/11/03 19:42:48 by parkjoung        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

int					ft_str_len(char *str)
{
	int result;

	result = 0;
	while (*str)
	{
		str++;
		result++;
	}
	return (result);
}

char				*ft_strdup(char *str)
{
	char	*result;
	char	*temp;

	if (!(result = (char *)malloc(sizeof(char) * ft_str_len(str) + 1)))
		return (0);
	temp = result;
	while (*str)
	{
		*result = *str;
		str++;
		result++;
	}
	*result = '\0';
	return (temp);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int					index;
	struct s_stock_str	*result;

	if (!(result = malloc(sizeof(s_stock_str) * ac + 1)))
		return (NULL);
	while (index < ac)
	{
		result[index].size = ft_str_len(av[index]);
		result[index].str = av[index];
		result[index].copy = ft_strdup(av[index]);
		index++;
	}
	result[index].size = 0;
	result[index].str = 0;
	result[index].copy = 0;
	return (result);
}
