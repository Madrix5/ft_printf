/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrijime <adrijime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:21:11 by adrijime          #+#    #+#             */
/*   Updated: 2024/03/13 17:57:25 by adrijime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	w_sign(int n, t_vars *list)
{
	if (n == INT_MIN)
	{
		if (ft_putstr("-2147483648", list) == -1)
			return (-1);
	}
	if (n < 0)
	{
		if (ft_putchar('-', list) == -1)
			return (-1);
		n = -n;
	}
	if (n <= 9)
	{
		n += '0';
		if (ft_putchar(n, list) == -1)
			return (-1);
	}
	else
	{
		w_sign(n / 10, list);
		if (ft_putchar(n % 10 + '0', list) == -1)
			return (-1);
	}
	return (0);
}

static int	n_sign(unsigned int n, t_vars *list)
{
	if (n <= 9)
	{
		n += '0';
		if (ft_putchar(n, list) == -1)
			return (-1);
	}
	else
	{
		if (n_sign(n / 10, list) == -1)
			return (-1);
		if (ft_putchar(n % 10 + '0', list) == -1)
			return (-1);
	}
	return (0);
}

int	ft_putnbr(int n, int sign, t_vars *list)
{
	if (sign == 1)
	{
		if (w_sign(n, list) == -1)
			return (-1);
	}
	else
	{
		if (n_sign(n, list) == -1)
			return (-1);
	}
	return (0);
}
