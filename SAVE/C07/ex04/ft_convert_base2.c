/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joupark <joupark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 11:28:32 by joupark           #+#    #+#             */
/*   Updated: 2020/11/03 21:46:34 by parkjoung        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		str_len(char *str)
{
	int		index;
	char	*temp;

	index = 0;
	temp = str;
	if (temp == 0)
		return (0);
	while (*temp)
	{
		index++;
		temp++;
	}
	return (index);
}

int		num_len(int nbr, int base_number)
{
	int		result;

	result = 0;
	if (nbr == -2147483648)
	{
		result++;
		nbr = nbr / base_number; 
	}
	if (nbr < 0)
	{
		result++;
		nbr *= -1;
	}
	if (nbr == 0)
		return (1);
	while (nbr)
	{
		nbr /= base_number;
		result++;
	}
	return (result);
}

int		ft_possible_base(char *str, int len_str)
{
	int		index_1;
	int		index_2;
	char	*temp;

	index_1 = 0;
	temp = str;
	if (len_str <= 1)
		return (1);
	while (temp[index_1])
	{
		if (temp[index_1] == '+' || temp[index_1] == '-')
			return (1);
		index_2 = index_1 + 1;
		while (temp[index_2])
		{
			if (temp[index_1] == temp[index_2])
				return (1);
			index_2++;
		}
		index_1++;
	}
	return (0);
}

void	ft_print_nbr(int nbr, char *base, int base_number, char *result)
{
	int nbr_len;

	nbr_len = num_len(nbr, base_number);
	if (nbr == -2147483648)
	{
		ft_print_nbr(nbr / base_number, base, base_number, result - 1);
		*result = base[-1 * (nbr % base_number)];
		return ;
	}
	if (nbr < 0)
	{
		ft_print_nbr(-1 * nbr, base, base_number, result);
		return ;
	}
	if (nbr > base_number - 1)
		ft_print_nbr(nbr / base_number, base, base_number, result - 1);
	*result = base[nbr % base_number];
}

char	*ft_putnbr_base(int nbr, char *base)
{
	int		base_number;
	int		nbr_len;
	char	*result;

	base_number = str_len(base);
	nbr_len = num_len(nbr, base_number);
	if(!(result = (char *)malloc(sizeof(char) * nbr_len + 1)))
		return (0);
	if (nbr < 0)
		result[0] = '-';
	result[nbr_len] = '\0';
	if (ft_possible_base(base, base_number))
		return (NULL);
	ft_print_nbr(nbr, base, base_number, &result[nbr_len - 1]);
	return (result);
}
