/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 16:56:09 by apissier          #+#    #+#             */
/*   Updated: 2017/01/13 16:54:25 by apissier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../libft/libft.h"
# define BUFF_SIZE 21

typedef	unsigned short		t_tro[6];
typedef unsigned short		t_map[16];

int		ft_is_out_under(int y, t_tro tetro, int index);
int		ft_read_file(char *str, unsigned short *all_tetros, int *n,
		t_tro tetros[26]);
int		ft_error(void);
int		ft_fillit_error(void *ptr);
int		ft_get_tetro(char *str, unsigned short *all_tetros, t_tro tetro);
int		ft_solve(t_tro tetros[26], t_map map, int ind[5]);
int		ft_fillit(t_tro tetros[26], int n_tetros);
void	ft_print_result(t_tro tetros[26], int n_tetros, int size);
int		ft_print_tetro_on_map(t_tro tetro, int shift, t_map map, int index);
int		ft_move_tetro(t_tro tetro, int *shift, int *index, int size);

#endif
