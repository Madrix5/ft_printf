/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrijime <adrijime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:21:11 by adrijime          #+#    #+#             */
/*   Updated: 2024/02/15 17:04:30 by adrijime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	w_sign(int n, int count)
{
	int	m;

	if (n == INT_MIN)
	{
		count += ft_putstr("-2147483648");
		return (count);
	}
	if (n < 0)
	{
		n = -n;
		count += ft_putchar('-');
	}
	if (n <= 9)
	{
		n += '0';
		count += ft_putchar(n);
	}
	else
	{
		m = n % 10 + '0';
		w_sign(n / 10, count);
		count++;
		count += ft_putchar(m);
	}
	return (count);
}

static int	n_sign(int n, int count)
{
	int	m;

	if (n == INT_MIN)
	{
		count += ft_putstr("2147483648");
		return (count);
	}
	if (n < 0)
		n = -n;
	if (n <= 9)
	{
		n += '0';
		count += ft_putchar(n);
	}
	else
	{
		m = n % 10 + '0';
		count++;
		w_sign(n / 10, count);
		count += ft_putchar(m);
	}
	return (count);
}

int	ft_putnbr(int n, int sign)
{
	int	count;

	count = 0;
	if (sign == 1)
		count = w_sign(n, count);
	else
		count = n_sign(n, count);
	return (count);
}
