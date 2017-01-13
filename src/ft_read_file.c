/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 15:56:30 by apissier          #+#    #+#             */
/*   Updated: 2017/01/13 16:52:48 by apissier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static int		n_char(char *t, char c)
{
	int			n;

	n = 0;
	while (*t)
		n += (c == *(t++));
	return (n);
}

/*
** valid_shape can only be used with a valid grid with a valid nbr of '#'s
*/

static int		valid_shape(char *tetro)
{
	int			i;
	int			total;
	int			n;

	n = 0;
	total = 0;
	i = 0;
	while (i < 20)
	{
		n = 0;
		if (tetro[i] == '#')
		{
			n += (i <= 14 ? tetro[i + 5] == '#' : 0) + 	\
				(i >= 5 ? tetro[i - 5] == '#' : 0) + 	\
				(i >= 1 ? tetro[i - 1] == '#' : 0) + 	\
				(i <= 18 ? tetro[i + 1] == '#' : 0);
			if (n == 0)
				return (0);
		}
		i++;
		total += n;
	}
	return (total);
}

static int		ft_isvalid(char *tetro)
{
	return (*tetro && \
			ft_strlen(tetro) == 20 && \
			tetro[4] == '\n' && \
			tetro[9] == '\n' && \
			tetro[14] == '\n' && \
			tetro[19] == '\n' && \
			n_char(tetro, '\n') >= 3 && \
			n_char(tetro, '.') == 12 && \
			n_char(tetro, '#') == 4 && \
			valid_shape(tetro) >= 6);
}

static int		ft_parse_buf(char buf[BUFF_SIZE + 1], int *n,\
							unsigned short *all_tetros, t_tro tetros[26])
{
	buf[BUFF_SIZE - 1] = '\0';
	if (!ft_isvalid(buf))
		return (0);
	ft_get_tetro(buf, all_tetros, tetros[(*n)++]);
	ft_bzero(buf, BUFF_SIZE + 1);
	return (1);
}

int				ft_read_file(char *str, unsigned short *all_tetros,
				int *n, t_tro tetros[26])
{
	int			fd;
	ssize_t		ret;
	char		buf[BUFF_SIZE + 1];
	int			count;
	int			valid;

	ret = 1;
	count = 0;
	valid = 1;
	ft_bzero(buf, BUFF_SIZE + 1);
	if ((fd = open(str, O_RDONLY)) != -1)
		while (valid)
		{
			if ((ret = read(fd, buf, BUFF_SIZE)) <= 0)
				break ;
			count += ret;
			valid = ft_parse_buf(buf, n, all_tetros, tetros);
		}
	if (fd == -1 || close(fd) == -1 || ret == -1 || count % 21 != 20 || !valid)
		return (0);
	return (1);
}
