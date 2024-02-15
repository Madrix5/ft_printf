/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrijime <adrijime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 20:00:20 by adrijime          #+#    #+#             */
/*   Updated: 2024/02/15 17:48:05 by adrijime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	ft_percent(va_list ap, char	c)
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

int	main(void)
{
	char	c;
	int		mi;
	int		i;
	unsigned long long n;
	char	*ch;
	char 	*str;
	int org;
	int mio;

	c = 'h';
	mi = -54;
	i = 573987;
	n = 12873812763;
	ch = &c;
	str = "Soy Eduardo Manos Tijeras. Te corto el pelo?";
	// printf("-------------- CARACTER ---------------\n");
	// org = printf("ORI: %c\n", c);
	// mio = ft_printf("MIA: %c\n", c);
	// printf("%d ---- %d\n", org, mio);
	// printf("------------- STRING --------------\n");
	// org = printf("ORI: %s\n", str);
	// mio = ft_printf("MIA: %s\n", str);
	// printf("%d ---- %d\n", org, mio);
	// printf("------------- PUNTERO --------------\n");
	// org = printf("ORI: %p\n", ch);
	// mio = ft_printf("MIA: %p\n", ch);
	// printf("%d ---- %d\n", org, mio);
	// printf("------------- DECIMAL --------------\n");
	// org = printf("ORI: %d\n", mi);
	// mio = ft_printf("MIA: %d\n", mi);
	// printf("%d ---- %d\n", org, mio);
	// printf("------------- DECIMAL: 10 --------------\n");
	// org = printf("ORI: %i\n", mi);
	// mio = ft_printf("MIA: %i\n", mi);
	// printf("%d ---- %d\n", org, mio);
	printf("------------- DECIMAL: 10 NO SIGNO --------------\n");
	org = printf("ORI: %u\n", i);
	mio = ft_printf("MIA: %u\n", i);
	printf("%d ---- %d\n", org, mio);
	// printf("------------- HEXADECIMAL MIN --------------\n");
	// org = printf("ORI: %x\n", i);
	// mio = ft_printf("MIA: %x\n", i);
	// printf("%d ---- %d\n", org, mio);
	// printf("------------- HEXADECIMAL MAY --------------\n");
	// org = printf("ORI: %X\n", i);
	// mio = ft_printf("MIA: %X\n", i);
	// printf("%d ---- %d\n", org, mio);
	// printf("------------- PORCENTAJE --------------\n");
	// org = printf("ORI: %%\n");
	// mio = ft_printf("MIA: %%\n");
	// printf("%d ---- %d\n", org, mio);
	return (0);
}
