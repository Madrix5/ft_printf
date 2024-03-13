/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrijime <adrijime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:36:41 by adrijime          #+#    #+#             */
/*   Updated: 2024/03/13 16:27:27 by adrijime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_writing(unsigned long n, t_vars *list)
{
	char	*base;

	base = "0123456789abcdef";
	if (ft_putchar(base[n], list) == -1)
		return (-1);
	return (0);
}

static int	ft_recursive(unsigned long pointer, t_vars *list)
{
	if (pointer <= 15)
	{
		if (ft_writing(pointer, list) == -1)
			return (-1);
	}
	else
	{
		ft_recursive(pointer / 16, list);
		ft_recursive(pointer % 16, list);
	}
	return (0);
}

int	ft_point(unsigned long pointer, t_vars *list)
{
	if (write(1, "0x", 2) == -1)
		return (-1);
	list->count += 2;
	if (ft_recursive(pointer, list) == -1)
		return (-1);
	return (0);
}
