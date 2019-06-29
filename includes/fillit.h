/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrooks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 19:17:09 by acrooks           #+#    #+#             */
/*   Updated: 2019/04/01 21:52:45 by gabshire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE 21

# include <fcntl.h>
# include "../libft/libft.h"

typedef	struct					s_tetra
{
	int							x[4];
	int							y[4];
	char						c;
	struct s_tetra				*next;
}								t_tetra;

int								main(int ac, char **av);
int								ft_check_right(char *str, int i);
int								ft_validate_tet(char *str, int i);
char							**paste_tetra(char **map, t_tetra *tetra,
int size);
char							**delete_tetra(char **map, t_tetra *tetra,
int size);
char							**new_tetra_map(char **map, int size);
int								check_tetra(char **map, t_tetra *tetra,
int size);
void							ft_print_map(char **map);
void							coord_in_struct(t_tetra **temp, char *str);
int								num_tetra(char *str);
t_tetra							*data_in_struct(char *str, char ch, int begin);
char							*read_file(int fd);
void							coord_xy(t_tetra **tetra, int x, int y);
char							**move_on_map(char **tetra_map, t_tetra *tetra,
int size);
void							core(t_tetra *tetra);
int								min_size(t_tetra *tetra);
void							ft_clean_map(char **map);

#endif
