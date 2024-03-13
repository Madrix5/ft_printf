/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrijime <adrijime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 20:04:21 by adrijime          #+#    #+#             */
/*   Updated: 2024/03/13 13:30:59 by adrijime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

//---------- Librerias ---------//
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>

//---------- Funciones ---------//
int	ft_printf(char const *str, ...);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr(int n, int sign);
int	ft_putnbr_base(unsigned int n, int mayus);
int	ft_point(unsigned long pointer);
typedef struct s_vars
{
	int	count;
}	t_vars;

#endif
