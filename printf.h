/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrijime <adrijime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 20:04:21 by adrijime          #+#    #+#             */
/*   Updated: 2024/02/14 19:39:47 by adrijime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

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
int	ft_putnbr_base(unsigned long long n, int mayus);

#endif
