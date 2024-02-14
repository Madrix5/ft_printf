/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrijime <adrijime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 20:00:20 by adrijime          #+#    #+#             */
/*   Updated: 2024/02/14 18:19:34 by adrijime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	ft_percent(va_list ap, char	c, int res)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar_fd(va_arg(ap, int), res);
	else if (c == 's')
		count += ft_putstr_fd(va_arg(ap, char *), res);
	// else if (c == 'p')
	// 	count += ft_putnbr_base(va_arg(ap, unsigned long long), 16, res, 0, 0);
	// else if (c == 'd')
	// 	count += ft_putnbr(va_arg(ap, int), 10, res, 1, 0);
	// else if (c == 'i')
	// 	count += ft_putnbr(va_arg(ap, int), 10, res, 1, 0);
	// else if (c == 'u')
	// 	count += ft_putnbr(va_arg(ap, int), 10, res, 0, 0);
	// else if (c == 'x')
	// 	count += ft_putnbr_base(va_arg(ap, unsigned long long), 16, res, 0, 0);
	// else if (c == 'X')
	// 	count += ft_putnbr_base(va_arg(ap, unsigned long long), 16, res, 0, 1);
	else if (c == '%')
		count += ft_putchar_fd('%', res);
	if (count == -1)
		return (-1);
	return (res + count);
}

// static int	ft_percent_bonus(char c)
// {
// 	return (1);
// }

static int	ft_checker(va_list ap, char const *str, int res)
{
	int	i;

	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] != '%')
		{
			if ((ft_putchar_fd(str[i], res)) == -1)
				return (-1);
			i++;
			res++;
		}
		if (str[i] == '%')
		{
			i++;
			// if ((ft_checker_bonus(str[i], res)) == -1)
			// 	return (-1);
			if ((ft_percent(ap, str[i], res)) == -1)
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
	res = ft_checker(ap, str, res);
	if (res == -1)
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
	//int len;

	c = 'h';
	int org;
	int mio;
	// i = 54;
	// ch = &c;
	str = "Soy Eduardo Manos Tijeras. Te corto el pelo?";
	org = printf("ORI - Char: %c\n", c);
	mio = ft_printf("MIA - Char: %c\n", c);
	printf("%d ---- %d\n", org, mio);
	org = printf("ORI - String: %s\n", str);
	mio = ft_printf("MIA - String: %s\n", str);
	printf("%d ---- %d\n", org, mio);
	// printf("ORI - Pointer: %p\n", ch);
	// ft_printf("MIA - Pointer: %p\n", ch);
	// printf("ORI - Decimal: %d\n", i);
	// ft_printf("MIA - Decimal: %d\n", i);
	// printf("ORI - Entero base 10: %i", i);
	// ft_printf("MIA - Entero base 10: %i", i);
	// printf("ORI - Decimal base 10 sin signo: %u", i);
	// ft_printf("MIA - Decimal base 10 sin signo: %u", i);
	// printf("ORI - Hexadecimal minus: %u", i);
	// ft_printf("MIA - Hexadecimal minus: %u", i);
	// printf("ORI - Hexadecimal mayus: %u", i);
	// ft_printf("MIA - Hexadecimal mayus: %u", i);
	org = printf("ORI - Porcentaje: %%\n");
	mio = ft_printf("MIO - Porcentaje: %%\n");
	printf("%d ---- %d\n", org, mio);
	return (0);
}