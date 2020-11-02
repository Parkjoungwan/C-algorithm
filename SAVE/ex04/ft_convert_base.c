/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parkjoungwan <whddhs6645@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 01:26:25 by parkjoung         #+#    #+#             */
/*   Updated: 2020/11/02 22:46:26 by joupark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_putnbr_base(int nbr, char *base);

int		str_len(char *str);

int		ft_possible_base(char *str, int len_str);

int		is_space(char c)
{
	return (c == ' ' || c == '\n' || c == '\t' ||
			c == '\f' || c == '\r' || c == '\v');
}

int		ft_change_num(char *base, char c)
{
	int	index;

	index = 0;
	while (*base)
	{
		if (*base == c)
			return (index);
		index++;
		base++;
	}
	return (-1);
}

int		ft_atoi_base(char *str, char *base)
{
	int	pm;
	int	result;
	int	base_number;

	result = 0;
	pm = 1;
	base_number = str_len(base);
	if (ft_possible_base(base, base_number))
		return (0);
	while (is_space(*str))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			pm *= -1;
		str++;
	}
	while (ft_change_num(base, *str) != -1)
	{
		result *= base_number;
		result += ft_change_num(base, *str);
		str++;
	}
	return (result * pm);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		num;
	char	*result;

	num = ft_atoi_base(nbr, base_from);
	printf("%d\n", num);
	result = ft_putnbr_base(num, base_to);
	return (result);
}
