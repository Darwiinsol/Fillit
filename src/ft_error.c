/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 18:01:49 by apissier          #+#    #+#             */
/*   Updated: 2017/01/13 16:52:21 by apissier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int				ft_error(void)
{
	ft_putstr("error\n");
	return (0);
}

int				ft_fillit_error(void *ptr)
{
	if (ptr)
		free(ptr);
	ft_error();
	exit(3);
}
