/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrijime <adrijime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:50:12 by adrijime          #+#    #+#             */
/*   Updated: 2024/02/14 19:41:06 by adrijime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_putchar(char c)
{
	int	res;

	res = 0;
	if (!c)
		return (-1);
	write(1, &c, 1);
	res++;
	return (res);
}

int	ft_putstr(char *s)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	if (!s)
		return (-1);
	while (s[i] != '\0')
	{
		count += ft_putchar(s[i]);
		//write(1, &s[i], 1);
		i++;
	}
	return (count);
}
