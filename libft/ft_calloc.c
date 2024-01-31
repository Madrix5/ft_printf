/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrijime <adrijime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:35:28 by adrijime          #+#    #+#             */
/*   Updated: 2024/01/26 16:00:53 by adrijime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*string;
	size_t	i;

	i = 0;
	string = (void *)malloc(size * count);
	if (!string)
		return (NULL);
	ft_bzero(string, size * count);
	return (string);
}
