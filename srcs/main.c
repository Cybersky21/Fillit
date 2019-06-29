/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrooks <acrooks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 18:54:49 by acrooks           #+#    #+#             */
/*   Updated: 2019/05/31 20:43:55 by acrooks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		freetemp(t_tetra *temp)
{
	t_tetra	*list;
	t_tetra *tmp;

	list = temp;
	if (temp != NULL)
	{
		while (list != NULL)
		{
			tmp = list->next;
			free(list);
			list = tmp;
		}
	}
	temp = NULL;
}

int				main(int ac, char **av)
{
	char	*tetras;
	t_tetra	*tetra_data;
	int		fd;

	if (ac == 2)
	{
		fd = ft_read_file(av[1]);
		tetras = read_file(fd);
		if (!tetras)
		{
			ft_putendl("error");
			return (0);
		}
		ft_close_file(fd);
		tetra_data = data_in_struct(tetras, 'A', 0);
		free(tetras);
		core(tetra_data);
		freetemp(tetra_data);
		return (0);
	}
	ft_putendl("use the map");
	return (0);
}
