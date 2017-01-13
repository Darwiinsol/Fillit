/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamicel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 15:07:40 by pamicel           #+#    #+#             */
/*   Updated: 2017/01/13 17:56:16 by apissier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>

static size_t	ft_strlen(const char *c)
{
	size_t		len;

	len = 0;
	while (c[len])
		len++;
	return (len);
}

void			ft_putstr(char const *str)
{
	size_t		n;

	n = ft_strlen(str);
	write(1, str, n);
}
