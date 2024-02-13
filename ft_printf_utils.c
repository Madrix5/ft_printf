/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrijime <adrijime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:50:12 by adrijime          #+#    #+#             */
/*   Updated: 2024/02/13 19:52:21 by adrijime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_putchar_fd(char c, int fd, int res)
{
	if (!fd || !c)
		return (-1);
	write(fd, &c, 1);
	res++;
	return (res);
}

int	ft_putstr_fd(char *s, int fd, int res)
{
	int	i;

	i = 0;
	if (!s || !fd)
		return (-1);
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
		res++;
	}
	return (res);
}
