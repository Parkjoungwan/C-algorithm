/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parkjoungwan <whddhs6645@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 19:43:24 by parkjoung         #+#    #+#             */
/*   Updated: 2020/11/03 20:44:38 by parkjoung        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
	write(1, "\n", 1);
}

void	ft_putnum(int num)
{
	char temp;

	if (num == 0)
		write(1, "0", 1);
	while (num)
	{
		temp = num % 10 + '0';
		write(1, &temp, 1);
		num /= 10;
	}
	write(1, "\n", 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	index;

	index = 0;
	while (par[index].str)
	{
		ft_putstr(par[index].str);
		ft_putnum(par[index].size);
		ft_putstr(par[index].copy);
		index++;
	}
}
