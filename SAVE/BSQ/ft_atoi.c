/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joupark <joupark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 19:53:55 by joupark           #+#    #+#             */
/*   Updated: 2020/11/04 00:32:23 by parkjoung        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_space(char c)
{
	if (c == '\t' || c == '\r' || c == '\n' ||
			c == ' ' || c == '\f' || c == '\v')
		return (1);
	return (0);
}

int		ft_atoi(char *str)
{
	int pm;
	int result;

	pm = 1;
	result = 0;
	while (ft_space(*str))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			pm *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result *= 10;
		result += *str - '0';
		str++;
	}
	return (result * pm);
}
