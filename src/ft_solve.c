/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamicel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 15:58:22 by pamicel           #+#    #+#             */
/*   Updated: 2017/01/13 16:53:02 by apissier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

/*
** 		arguments to ft_solve
** ind[4] : size of the square (aka y or x in some functions)
** ind[3] : line index (from which the placement is done) in map
** ind[2] : shift value for the tetromino
** ind[1] : current tetromino (index in the list of tetros)
** ind[0] : number of tetrominos (length of the list of tetros)
*/

static void			ft_erase_tetro_from_map(t_tro tetro, int shift, t_map map, \
					int index)
{
	map[0 + index] ^= tetro[0] >> shift;
	if (tetro[1])
	{
		map[1 + index] ^= tetro[1] >> shift;
		if (tetro[2])
		{
			map[2 + index] ^= tetro[2] >> shift;
			if (tetro[3])
				map[3 + index] ^= tetro[3] >> shift;
		}
	}
}

static void			ft_set_ind_next_tetro(int rec_ind[5], int ind[5])
{
	rec_ind[4] = ind[4];
	rec_ind[3] = 0;
	rec_ind[2] = 0;
	rec_ind[1] = ind[1] + 1;
	rec_ind[0] = ind[0];
}

int					ft_solve(t_tro tetros[26], t_map map, int ind[5])
{
	int				rec_ind[5];

	if (ind[1] == ind[0])
		return (1);
	while (1)
	{
		while (!ft_print_tetro_on_map(tetros[ind[1]], ind[2], map, ind[3]))
			if (!ft_move_tetro(tetros[ind[1]], &(ind[2]), &(ind[3]), ind[4]))
				return (0);
		ft_set_ind_next_tetro(rec_ind, ind);
		if (ft_solve(tetros, map, rec_ind))
			return (1);
		else
		{
			ft_erase_tetro_from_map(tetros[ind[1]], ind[2], map, ind[3]);
			if (!ft_move_tetro(tetros[ind[1]], &(ind[2]), &(ind[3]), ind[4]))
				return (0);
		}
	}
	return (1);
}
