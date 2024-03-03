/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrijime <adrijime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 19:11:30 by adrijime          #+#    #+#             */
/*   Updated: 2024/02/15 19:11:49 by adrijime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	if (!s)
		s = "(null)";
	while (s[i] != '\0')
	{
		count += ft_putchar(s[i]);
		i++;
	}
	return (count);
}
