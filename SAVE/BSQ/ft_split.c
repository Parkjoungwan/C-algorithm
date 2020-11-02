/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjeong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 19:31:58 by sjeong            #+#    #+#             */
/*   Updated: 2020/10/28 12:05:52 by sjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int			check_charset(char c, char *charset)
{
	while (*charset != 0)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

long long	get_count(char *str, char *charset)
{
	long long cnt;

	cnt = 0;
	while (*str != 0)
	{
		if (check_charset(*str, charset) == 0)
		{
			cnt++;
			while (*str != 0 && check_charset(*str, charset) == 0)
				str++;
		}
		str++;
	}
	return (cnt);
}

void		ft_str_to_cpy(char *dest, char *from, char *to)
{
	while (from < to)
		*(dest++) = *(from++);
	*dest = 0;
}

char		**ft_split(char *str, char *charset)
{
	char		**res;
	long long	idx;
	char		*from;

	res = (char**)malloc(sizeof(char*) * (get_count(str, charset) + 1));
	idx = 0;
	while (*str != 0)
	{
		if (check_charset(*str, charset) == 0)
		{
			from = str;
			while (*str != 0 && check_charset(*str, charset) == 0)
				str++;
			res[idx] = (char*)malloc(sizeof(char) * (str - from + 1));
			ft_str_to_cpy(res[idx++], from, str);
		}
		str++;
	}
	res[idx] = 0;
	return (res);
}
