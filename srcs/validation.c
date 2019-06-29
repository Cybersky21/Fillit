/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrooks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 18:55:11 by acrooks           #+#    #+#             */
/*   Updated: 2019/02/15 18:55:12 by acrooks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_right(char *str, int i)
{
	int	count;

	count = 0;
	if (i - 1 >= 0 && str[i - 1] == '#')
		count++;
	if (i - 5 >= 0 && str[i - 5] == '#')
		count++;
	if (str[i + 1] == '#' && i + 1 < 20)
		count++;
	if (str[i + 5] == '#' && i + 5 < 20)
		count++;
	return (count);
}

int		ft_validate_tet(char *str, int i)
{
	int			dots;
	int			sharps;
	int			connect;

	i = -1;
	dots = 0;
	sharps = 0;
	connect = 0;
	while (++i < 20)
	{
		if (str[i] != '.' && str[i] != '#' && str[i] != '\n')
			return (0);
		if (str[i] == '#')
		{
			sharps++;
			if (!(connect += ft_check_right(str, i)))
				return (0);
		}
		if (str[i] == '.')
			dots++;
	}
	if (str[4] != '\n' || str[9] != '\n' || str[14] != '\n' || str[19] != '\n'
		|| dots != 12 || sharps != 4 || (connect != 6 && connect != 8))
		return (0);
	return (1);
}
