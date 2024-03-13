/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrijime <adrijime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 19:56:44 by adrijime          #+#    #+#             */
/*   Updated: 2024/03/08 16:36:26 by adrijime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hex(unsigned int n, int condition)
{
	char	*base;

	if (condition == 1)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (ft_putchar(base[n]) == -1)
		return (-1);
	return (0);
}

static int	ft_nbrput(unsigned int n, int count, int condition)
{
	if (n <= 15)
	{
		count++;
		if (ft_hex((unsigned int)n, condition) == -1)
			return (-1);
	}
	else
	{
		count += ft_nbrput(n / 16, count, condition);
		if (ft_nbrput(n % 16, count, condition) == -1)
			return (-1);
		count++;
	}
	return (count);
}

int	ft_putnbr_base(unsigned int n, int condition)
{
	int	count;

	count = 0;
	if (condition == 1)
	{
		count += ft_nbrput(n, count, 1);
		if (count == -1)
			return (-1);
	}
	else
		count += ft_nbrput(n, count, 0);
	if (count == -1)
		return (-1);
	return (count);
}
