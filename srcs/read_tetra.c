/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_tetra.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrooks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 19:55:03 by acrooks           #+#    #+#             */
/*   Updated: 2019/04/02 19:55:04 by acrooks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		coord_in_struct(t_tetra **temp, char *str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '#')
		{
			(*temp)->x[j] = i % 5;
			(*temp)->y[j] = i / 5;
			j++;
		}
		i++;
	}
}

int			num_tetra(char *str)
{
	int i;
	int diez;
	int count;

	i = 0;
	diez = 0;
	while (str[i])
	{
		if (str[i] == '#')
			diez++;
		i++;
	}
	count = diez / 4;
	return (count);
}

t_tetra		*data_in_struct(char *str, char ch, int begin)
{
	int		count_tet;
	t_tetra	*temp;
	t_tetra	*temp2;
	char	*sub;

	count_tet = num_tetra(str);
	if (!(temp2 = (t_tetra*)malloc(sizeof(t_tetra) * 2)))
		return (0);
	temp = temp2;
	while (count_tet > 0)
	{
		sub = ft_strsub(str, 0 + begin, 20);
		coord_in_struct(&temp, sub);
		temp->c = ch;
		if (!(temp->next = (t_tetra *)malloc(sizeof(t_tetra))))
			return (0);
		free(sub);
		temp = temp->next;
		ch++;
		begin += 21;
		count_tet--;
	}
	temp->next = NULL;
	return (temp2);
}

static int	error_statements(char *buf, char *tetras, int i)
{
	if (buf[BUFF_SIZE - 1] && tetras)
	{
		free(tetras);
		return (1);
	}
	if (i > 26 && tetras)
	{
		free(tetras);
		return (1);
	}
	return (0);
}

char		*read_file(int fd)
{
	char	*tetras;
	int		i;
	char	buf[BUFF_SIZE + 1];
	int		ret;

	if ((fd < 0 || read(fd, buf, 0) < 0))
		return (0);
	tetras = ft_strnew(BUFF_SIZE * 26);
	i = 0;
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		if (ft_validate_tet(buf, ret) == 0)
		{
			free(tetras);
			return (0);
		}
		ft_strncpy(tetras + BUFF_SIZE * i, buf, ret);
		tetras[BUFF_SIZE * i + ret] = 0;
		++i;
	}
	if (error_statements(buf, tetras, i) == 1)
		return (0);
	return (tetras);
}
