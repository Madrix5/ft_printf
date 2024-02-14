/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrijime <adrijime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 20:04:21 by adrijime          #+#    #+#             */
/*   Updated: 2024/02/14 18:26:37 by adrijime         ###   ########.fr       */
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
int	ft_putchar_fd(char c, int res);
int	ft_putstr_fd(char *s, int res);
int	ft_putnbr(int n, int res, int sign);
int	ft_putnbr_base(va_list ap, int base, int res, int sign, int mayus);

#endif
