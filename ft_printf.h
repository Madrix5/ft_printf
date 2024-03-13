/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrijime <adrijime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 20:04:21 by adrijime          #+#    #+#             */
/*   Updated: 2024/03/13 18:00:52 by adrijime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

//---------- Librerias ---------//
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>

//---------- Structura ---------//
typedef struct s_vars
{
	int	count;
}	t_vars;

//---------- Funciones ---------//
int	ft_printf(char const *str, ...);
int	ft_putchar(char c, t_vars *list);
int	ft_putstr(char *s, t_vars *list);
int	ft_putnbr(int n, int sign, t_vars *list);
int	ft_putnbr_b(unsigned int n, int mayus, t_vars *list);
int	ft_point(unsigned long pointer, t_vars *list);

#endif
