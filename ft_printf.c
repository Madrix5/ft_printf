/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrijime <adrijime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 20:00:20 by adrijime          #+#    #+#             */
/*   Updated: 2024/02/12 12:13:45 by adrijime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_percent(char	c)
{
	return ;
}

static int	ft_checker(va_list ap, char const *str, int res)
{
	return (0);
}

int	ft_printf(char const *str, ...)
{
	int		res;
	va_list	ap;

	res = 0;
	va_start(ap, str);
	if (ft_checker(ap, str, res) == -1)
		return (-1);
	va_end(ap);
	return (res);
}