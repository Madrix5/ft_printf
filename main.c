/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrijime <adrijime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:35:19 by adrijime          #+#    #+#             */
/*   Updated: 2024/03/13 18:03:05 by adrijime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	char				c = 'h';
	// int					i = INT_MIN;
	// int					m = INT_MAX;
	// char				*ch;
	char 				*str = "Hola";
	// int					org;
	int					mio;

	// ch = &c;
	// printf("------------ Letras -------------\n");
	// org = printf("%c, %s, %%\n", c, str);
	mio = ft_printf("%c, %s, %%\n", c, str);
	// printf("%d --- %d\n", org, mio);
	// printf("------------ Hexade -------------\n");
	// org = printf("%p, %x, %X\n", ch, i, m);
	// mio = ft_printf("%p, %x, %X\n", ch, i, m);
	// printf("%d --- %d\n", org, mio);
	// printf("------------ Numeros -------------\n");
	// org = printf("%d, %i, %u\n", i, i, i);
	// mio = ft_printf("%d, %i, %u\n", i, i, i);
	// printf("%d --- %d\n", org, mio);

	// printf("%x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x\n", 0, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6, 7);
	// ft_printf("%x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x\n", 0, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6, 7);
	return (0);
}