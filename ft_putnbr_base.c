/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrijime <adrijime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 19:56:44 by adrijime          #+#    #+#             */
/*   Updated: 2024/02/15 19:01:33 by adrijime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_hex(unsigned long long n, int condition)
{
	char	*base;

	if (condition == 1)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	ft_putchar(base[n]);
}

static int	ft_nbrput(unsigned long long n, int count, int condition)
{
	if (n <= 15)
	{
		count++;
		ft_hex(n, condition);
	}
	else
	{
		count += ft_nbrput(n / 16, count, condition);
		ft_nbrput(n % 16, count, condition);
		count++;
	}
	return (count);
}

int	ft_putnbr_base(unsigned long long n, int condition)
{
	int	count;

	count = 0;
	if (condition == 2)
	{
		write(1, "0x", 2);
		count += ft_nbrput(n, count, 0);
		count += 2;
	}
	else if (condition == 1)
		count += ft_nbrput(n, count, 1);
	else
		count += ft_nbrput(n, count, 0);
	return (count);
}
