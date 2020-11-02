/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parkjoungwan <whddhs6645@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 18:24:26 by parkjoung         #+#    #+#             */
/*   Updated: 2020/11/01 19:46:36 by parkjoung        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen_0(char *str)
{
	int	index;

	index = 0;
	while (*str++)
		index++;
	return (index + 1);
}

char	*ft_strdup(char *str)
{
	char	*temp;
	char	*result;
	int		size;
	int		index;

	index = 0;
	temp = str;
	size = ft_strlen_0(temp);
	if (!(result = (char *)malloc(sizeof(char) * size)))
		return (NULL);
	while (*temp)
	{
		result[index] = *temp;
		temp++;
		index++;
	}
	result[index] = '\0';
	return (result);
}
