/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamicel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 19:05:59 by pamicel           #+#    #+#             */
/*   Updated: 2016/11/09 21:44:00 by pamicel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

static void		*ft_memset(void *b, int c, size_t len)
{
	size_t		i;

	i = 0;
	while (i < len)
		((unsigned char*)b)[i++] = (unsigned char)c;
	return (b);
}

void			ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
