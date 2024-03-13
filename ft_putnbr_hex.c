/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrijime <adrijime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 19:56:44 by adrijime          #+#    #+#             */
/*   Updated: 2024/03/13 18:00:26 by adrijime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hexa(unsigned int n, int condition, t_vars *list)
{
	char	*base;

	if (condition == 1)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (ft_putchar(base[n], list) == -1)
		return (-1);
	return (0);
}

static int	ft_nbrput(unsigned int n, int condition, t_vars *list)
{
	if (n <= 15)
	{
		if (ft_hexa((unsigned int)n, condition, list) == -1)
			return (-1);
		list->count++;
	}
	else
	{
		if (ft_nbrput(n / 16, condition, list) == -1)
			return (-1);
		if (ft_nbrput(n % 16, condition, list) == -1)
			return (-1);
	}
	return (0);
}

int	ft_putnbr_b(unsigned int n, int condition, t_vars *list)
{
	if (condition == 1)
	{
		if (ft_nbrput(n, 1, list) == -1)
			return (-1);
	}
	else
	{
		if (ft_nbrput(n, 0, list) == -1)
			return (-1);
	}
	return (0);
}
