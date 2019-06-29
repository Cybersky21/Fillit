/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_tetra_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrooks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 19:40:30 by acrooks           #+#    #+#             */
/*   Updated: 2019/04/02 19:40:32 by acrooks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**paste_tetra(char **map, t_tetra *tetra, int size)
{
	int x;
	int y;
	int i;

	i = 0;
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			if (tetra->y[i] == y && tetra->x[i] == x)
			{
				map[y][x] = tetra->c;
				i++;
			}
			x++;
		}
		y++;
	}
	return (map);
}

char	**delete_tetra(char **map, t_tetra *tetra, int size)
{
	int x;
	int y;

	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			if (map[y][x] == tetra->c)
				map[y][x] = '.';
			x++;
		}
		y++;
	}
	return (map);
}
