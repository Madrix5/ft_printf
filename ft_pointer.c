/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrijime <adrijime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:36:41 by adrijime          #+#    #+#             */
/*   Updated: 2024/03/13 12:28:46 by adrijime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_writing(unsigned long n)
{
	char	*base;

	base = "0123456789abcdef";
	if (ft_putchar(base[n]) == -1)
		return (-1);
	return (0);
}

int	ft_point(unsigned long pointer)
{
	int	count;

	if (write(1, "0x", 2) == -1)
		return (-1);
	count = 2;
	if (pointer <= 15)
	{
		if (ft_writing(pointer) == -1)
			return (-1);
		count++;
	}
	else
	{
		count += ft_point(pointer / 16);
		ft_point(pointer % 16);
		count++;
	}
	return (count);
}
