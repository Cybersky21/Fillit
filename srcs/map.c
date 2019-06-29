/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrooks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 20:18:19 by acrooks           #+#    #+#             */
/*   Updated: 2019/03/01 20:18:20 by acrooks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**new_tetra_map(char **map, int size)
{
	int x;
	int y;

	ft_clean_map(map);
	if (!(map = (char **)malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	y = 0;
	while (y < size)
	{
		if (!(map[y] = (char *)malloc(sizeof(char) * (size + 1))))
			return (NULL);
		x = 0;
		while (x < size)
		{
			map[y][x] = '.';
			x++;
		}
		map[y][x] = '\0';
		y++;
	}
	map[y] = NULL;
	return (map);
}

int		check_tetra(char **map, t_tetra *tetra, int size)
{
	int i;
	int x;
	int y;

	i = 0;
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			if (tetra->y[i] < size && tetra->x[i] < size &&
				map[tetra->y[i]][tetra->x[i]] == '.')
			{
				i++;
				if (i == 4)
					return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

void	ft_print_map(char **map)
{
	int	i;

	if (!map)
	{
		ft_putendl("error");
		return ;
	}
	i = 0;
	while (map[i])
	{
		ft_putendl(map[i]);
		i++;
	}
}

void	ft_clean_map(char **map)
{
	size_t	i;

	i = 0;
	while (map && map[i])
		free(map[i++]);
	if (map)
		free(map);
}
