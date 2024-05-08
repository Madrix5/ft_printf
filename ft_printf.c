/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrijime <adrijime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:00:16 by adrijime          #+#    #+#             */
/*   Updated: 2024/05/08 19:38:23 by adrijime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		count;
	int		i;

	va_start(ap, str);
	i = 0;
	count = 0;
	while (str[i] && count != -1)
	{
		if (str[i] == '%')
		{
			if (letter(str[i + 1], ap, &count) == -1)
				return (-1);
			i++;
		}
		else
			ft_putchar(str[i], &count);
		if (str[i])
			i++;
	}
	va_end(ap);
	return (count);
}

/*
int	main(void)
{
	int		count;
	char	*name = "Adrian";
	int		edad = 27;
	char	*str;

	str = &name;
	count = ft_printf("hola soy %s y tengo %i\n", name, edad);
	printf("%i\n", count);
	count = printf("hola soy %s y tengo %i\n", name, edad);
	printf("%i\n", count);
}
*/
