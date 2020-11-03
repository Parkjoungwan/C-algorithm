/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parkjoungwan <whddhs6645@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 00:17:20 by parkjoung         #+#    #+#             */
/*   Updated: 2020/11/04 00:18:23 by parkjoung        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_open_file(char *file_name);

int		main(int argc, char **argv)
{
	if (argc == 2)
		ft_open_file(argv[1]);
}
