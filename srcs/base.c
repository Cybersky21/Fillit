/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrooks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 19:36:35 by acrooks           #+#    #+#             */
/*   Updated: 2019/04/02 19:36:37 by acrooks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	coord_xy(t_tetra **tetra, int x, int y)
{
	int	first_x;
	int first_y;
	int i;

	i = 0;
	first_x = 20;
	first_y = 20;
	while (i < 4)
	{
		if ((*tetra)->x[i] < first_x)
			first_x = (*tetra)->x[i];
		if ((*tetra)->y[i] < first_y)
			first_y = (*tetra)->y[i];
		i++;
	}
	i--;
	while (i >= 0)
	{
		(*tetra)->x[i] = (*tetra)->x[i] - first_x + x;
		(*tetra)->y[i] = (*tetra)->y[i] - first_y + y;
		i--;
	}
}

char	**move_on_map(char **tetra_map, t_tetra *tetra, int size)
{
	int		x;
	int		y;
	char	**map;

	if (tetra->next == NULL)
		return (tetra_map);
	map = NULL;
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			coord_xy(&tetra, x, y);
			if (check_tetra(tetra_map, tetra, size))
				map = move_on_map(paste_tetra(tetra_map, tetra, size),
						tetra->next, size);
			if (map)
				return (map);
			tetra_map = delete_tetra(tetra_map, tetra, size);
			x++;
		}
		y++;
	}
	return (NULL);
}

void	core(t_tetra *tetra)
{
	char	**result;
	char	**tetra_map;
	int		size;
	int		i;

	size = min_size(tetra);
	tetra_map = NULL;
	tetra_map = new_tetra_map(tetra_map, size);
	result = NULL;
	while (!(result = move_on_map(tetra_map, tetra, size)))
	{
		size++;
		i = 0;
		while (result && result[i])
			free(result[i++]);
		tetra_map = new_tetra_map(tetra_map, size);
	}
	ft_print_map(result);
	i = 0;
	while (result && result[i])
		free(result[i++]);
	if (result)
		free(result);
}

int		min_size(t_tetra *tetra)
{
	int i;

	i = 0;
	while (tetra != NULL && tetra->next != NULL)
	{
		tetra = tetra->next;
		i++;
	}
	return (ft_sqrt(i * 4));
}
