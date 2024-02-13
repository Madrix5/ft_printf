/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrijime <adrijime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 20:00:20 by adrijime          #+#    #+#             */
/*   Updated: 2024/02/13 19:21:11 by adrijime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_percent(va_list ap, char	c, int res)
{
	if (c == 'c' && (ft_putchar_fd(ap, 1, res)) == -1)
		return (-1);
	else if (c == 's' && (ft_putstr_fd(ap, 1, res)) == -1)
		return (-1);
	else if (c == 'p' && (ft_putnbr_base(ap, 16, res, 0, 0)) == -1)
		return (-1);
	else if (c == 'd' && (ft_putnbr_base(ap, 10, res, 1, 0)) == -1)
		return (-1);
	else if (c == 'i' && (ft_putnbr_base(ap, 10, res, 1, 0)) == -1)
		return (-1);
	else if (c == 'u' && (ft_putnbr_base(ap, 10, res, 0, 0)) == -1)
		return (-1);
	else if (c == 'x' && (ft_putnbr_base(ap, 16, res, 0, 0)) == -1)
		return (-1);
	else if (c == 'X' && (ft_putnbr_base(ap, 16, res, 0, 1)) == -1)
		return (-1);
	else if (c == '%' && (ft_putchar_fd('%', 1, res)) == -1)
		return (-1);
	return (res);
}

static int	ft_percent_bonus(char c)
{
	return (1);
}

static int	ft_checker(va_list ap, char const *str, int res)
{
	int	i;

	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] != '%')
		{
			if ((ft_putchar_fd(str[i], 1, res)) == -1);
				return (-1);
			i++;
			res++;
		}
		if (str[i] == '%')
		{
			i++;
			if ((ft_checker_bonus(str[i], res)) == -1)
				return (-1);
			else if ((ft_percent(ap, str[i], res)) == -1)
				return (-1);
			i++;
		}
	}
	return (res);
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

int	main(void)
{
	char	c;
	// int		i;
	// char	*ch;
	char 	*str;
	int len;

	c = 'h';
	// i = 54;
	// ch = &c;
	str = "Soy Eduardo Manos Tijeras. Te corto el pelo?";
	printf("Char: %c\n", c);
	ft_printf("Char: %c\n", c);
	printf("String: %s\n", str);
	ft_printf("String: %s\n", str);
	// printf("Pointer: %p\n", ch);
	// ft_printf("Pointer: %p\n", ch);
	// printf("Decimal: %d\n", i);
	// ft_printf("Decimal: %d\n", i);
	// printf("Entero base 10: %i", i);
	// ft_printf("Entero base 10: %i", i);
	// printf("Decimal base 10 sin signo: %u", i);
	// ft_printf("Decimal base 10 sin signo: %u", i);
	// printf("Hexadecimal minus: %u", i);
	// ft_printf("Hexadecimal minus: %u", i);
	// printf("Hexadecimal mayus: %u", i);
	// ft_printf("Hexadecimal mayus: %u", i);
	ft_printf("%%");
	return (0);
}