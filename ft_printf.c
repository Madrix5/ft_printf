/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrijime <adrijime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 20:00:20 by adrijime          #+#    #+#             */
/*   Updated: 2024/03/13 18:01:48 by adrijime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_percent(va_list ap, char c, t_vars *list)
{
	if (c == 'c' && ft_putchar(va_arg(ap, int), list) == -1)
		return (-1);
	else if (c == 's' && ft_putstr(va_arg(ap, char *), list) == -1)
		return (-1);
	else if (c == 'p' && ft_point(va_arg(ap, unsigned long), list) == -1)
		return (-1);
	else if (c == 'd' && ft_putnbr(va_arg(ap, int), 1, list) == -1)
		return (-1);
	else if (c == 'i' && ft_putnbr(va_arg(ap, int), 1, list) == -1)
		return (-1);
	else if (c == 'u' && ft_putnbr(va_arg(ap, unsigned int), 0, list) == -1)
		return (-1);
	else if (c == 'x' && ft_putnbr_b(va_arg(ap, unsigned int), 0, list) == -1)
		return (-1);
	else if (c == 'X' && ft_putnbr_b(va_arg(ap, unsigned int), 1, list) == -1)
		return (-1);
	else if (c == '%' && ft_putchar('%', list) == -1)
		return (-1);
	return (0);
}

static int	ft_checker(va_list ap, char const *str, t_vars *list)
{
	int	i;

	list->count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] != '%')
		{
			if ((ft_putchar(str[i], list)) == -1)
				return (-1);
			i++;
			list->count++;
		}
		if (str[i] == '%')
		{
			i++;
			if (ft_percent(ap, str[i], list) == -1)
				return (-1);
			i++;
		}
	}
	return (0);
}

int	ft_printf(char const *str, ...)
{
	va_list	ap;
	t_vars	*list;

	list = 0;
	va_start(ap, str);
	if (ft_checker(ap, str, list) == -1)
		return (-1);
	va_end(ap);
	return (list->count);
}
