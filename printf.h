/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrijime <adrijime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 20:04:21 by adrijime          #+#    #+#             */
/*   Updated: 2024/02/13 19:21:41 by adrijime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

//---------- Librerias ---------//
# include <stdarg.h>

//---------- Funciones ---------//
int	ft_printf(char const *str, ...);
int	ft_putchar_fd(char c, int fd, int res);
int	ft_putstr_fd(char *s, int fd, int res);
int	ft_putnbr_base(va_list ap, int base, int res, int sign, int mayus);

#endif
