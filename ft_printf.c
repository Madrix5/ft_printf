/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrijime <adrijime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 20:00:20 by adrijime          #+#    #+#             */
/*   Updated: 2024/02/13 16:35:48 by adrijime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_percent(va_list ap, char	c, int *res)
{
	if (c == 'c' && (ft_putchar_fd(c, 1)) == -1)
		return (-1);
	if (c == 's' && (ft_putstr_fd(ap, 1)) == -1)
		return (-1);
}

static int	ft_percent_bonus(char c)
{
	return (1);
}

static int	ft_checker(va_list ap, char const *str, int res, int *i)
{
	while (str[*i])
	{
		while (str[*i] && str[*i] != '%')
		{
			if ((ft_putchar_fd(str[*i], 1)) == -1);
				return (-1);
			i++;
			res++;
		}
		if (str[*i] == '%')
		{
			i++;
			if ((ft_checker_bonus(str[*i])) == -1)
				return (-1)
			else if ((ft_percent(ap, str[*i], &res)) == -1)
				return (-1);
			i++;
		}
	}
	return (res);
}

int	ft_printf(char const *str, ...)
{
	int		res;
	int		*i;
	va_list	ap;

	res = 0;
	i = 0;
	va_start(ap, str);
	if (ft_checker(ap, str, res, i) == -1)
		return (-1);
	va_end(ap);
	return (res);
}