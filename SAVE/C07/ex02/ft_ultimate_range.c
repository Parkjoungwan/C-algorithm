/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parkjoungwan <whddhs6645@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 20:18:07 by parkjoung         #+#    #+#             */
/*   Updated: 2020/11/01 22:10:37 by parkjoung        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int *result;
	int size;
	int index;

	index = 0;
	size = max - min;
	if (max < min)
	{
		*range = 0;
		return (0);
	}
	if (!(result = (int *)malloc(sizeof(int) * size)))
	{
		*range = 0;
		return (-1);
	}
	while (index < size)
		result[index++] = min++;
	*range = result;
	return (size);
}
