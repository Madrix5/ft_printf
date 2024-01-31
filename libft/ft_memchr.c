/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrijime <adrijime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:45:14 by adrijime          #+#    #+#             */
/*   Updated: 2024/01/21 17:29:20 by adrijime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		*sc;
	unsigned char		r;
	size_t				i;

	i = 0;
	r = (unsigned char)c;
	sc = (unsigned char *)s;
	while (i < n)
	{
		if (sc[i] == r)
			return ((void *)&sc[i]);
		i++;
	}
	return (0);
}
