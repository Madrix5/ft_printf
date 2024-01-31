/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrijime <adrijime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 19:31:20 by adrijime          #+#    #+#             */
/*   Updated: 2024/01/26 20:22:43 by adrijime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_putnbr(long n, char *str, int count)
{
	int	m;
	int	sign;

	sign = 0;
	str[count] = '\0';
	count--;
	if (n < 0)
	{
		n = -n;
		sign = 1;
	}
	if (n == 0)
		str[count] = '0';
	while (n != 0)
	{
		m = n % 10;
		n = n / 10;
		str[count] = m + '0';
		count--;
	}
	if (sign == 1)
		str[0] = '-';
	return (str);
}

static int	nbrlen(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		count;

	count = nbrlen(n);
	str = malloc(sizeof(char) * count + 1);
	if (!str)
		return (NULL);
	str = ft_putnbr(n, str, count);
	return (str);
}
