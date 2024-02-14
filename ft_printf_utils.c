/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrijime <adrijime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:50:12 by adrijime          #+#    #+#             */
/*   Updated: 2024/02/14 17:36:47 by adrijime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_putchar_fd(char c, int res)
{
	if (!c)
		return (-1);
	write(1, &c, 1);
	res++;
	return (res);
}

int	ft_putstr_fd(char *s, int res)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
		res++;
	}
	return (res);
}
