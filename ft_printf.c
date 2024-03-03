/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrijime <adrijime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 20:00:20 by adrijime          #+#    #+#             */
/*   Updated: 2024/02/15 19:03:46 by adrijime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_percent(va_list ap, char c)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar(va_arg(ap, int));
	else if (c == 's')
		count += ft_putstr(va_arg(ap, char *));
	else if (c == 'p')
		count += ft_putnbr_base(va_arg(ap, unsigned long long), 2);
	else if (c == 'd')
		count += ft_putnbr(va_arg(ap, int), 1);
	else if (c == 'i')
		count += ft_putnbr(va_arg(ap, int), 1);
	else if (c == 'u')
		count += ft_putnbr(va_arg(ap, int), 0);
	else if (c == 'x')
		count += ft_putnbr_base(va_arg(ap, unsigned long long), 0);
	else if (c == 'X')
		count += ft_putnbr_base(va_arg(ap, unsigned long long), 1);
	else if (c == '%')
		count += ft_putchar('%');
	if (count == -1)
		return (-1);
	return (count);
}

static int	ft_checker(va_list ap, char const *str, int res)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] != '%')
		{
			if ((ft_putchar(str[i])) == -1)
				return (-1);
			i++;
			res++;
		}
		if (str[i] == '%')
		{
			i++;
			count += ft_percent(ap, str[i]);
			if (res == -1)
				return (-1);
			i++;
		}
	}
	return (res + count);
}

int	ft_printf(char const *str, ...)
{
	int		res;
	va_list	ap;

	res = 0;
	va_start(ap, str);
	res = ft_checker(ap, str, res);
	if (res == -1)
		return (-1);
	va_end(ap);
	return (res);
}
