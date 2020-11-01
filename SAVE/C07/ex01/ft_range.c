/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parkjoungwan <whddhs6645@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 19:52:20 by parkjoung         #+#    #+#             */
/*   Updated: 2020/11/01 20:08:52 by parkjoung        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*result;
	int	size;
	int	index;
	
	if (max <= min)
		return (NULL);
	index = 0;
	size = max - min;
	if (!(result = (int *)malloc(sizeof(int) * size)))
		return (NULL);
	while (index < size)
	{
		result[index++] = min++;
	}
	return (result);
}
