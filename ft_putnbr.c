/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrijime <adrijime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:21:11 by adrijime          #+#    #+#             */
/*   Updated: 2024/03/07 16:53:38 by adrijime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	w_sign(int n)
{
	int	count;

	count = 0;
	if (n == INT_MIN)
	{
		count += ft_putstr("-2147483648");
		return (count);
	}
	if (n < 0)
	{
		count += ft_putchar('-');
		n = -n;
	}
	if (n <= 9)
	{
		n += '0';
		count += ft_putchar(n);
	}
	else
	{
		count += w_sign(n / 10);
		count += ft_putchar(n % 10 + '0');
	}
	return (count);
}

static int	n_sign(unsigned int n)
{
	int	count;

	count = 0;
	if (n <= 9)
	{
		n += '0';
		count += ft_putchar(n);
	}
	else
	{
		count += n_sign(n / 10);
		count += ft_putchar(n % 10 + '0');
	}
	return (count);
}

int	ft_putnbr(int n, int sign)
{
	int	count;

	count = 0;
	if (sign == 1)
		count = w_sign(n);
	else
		count = n_sign(n);
	if (count == -1)
		return (-1);
	return (count);
}
