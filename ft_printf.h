/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrijime <adrijime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 20:04:21 by adrijime          #+#    #+#             */
/*   Updated: 2024/02/13 17:52:28 by adrijime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

//---------- Librerias ---------//
# include <stdarg.h>

//---------- Funciones ---------//
int	ft_printf(char const *str, ...);
int	ft_putchar_fd(char c, int fd);
int	ft_putstr_fd(char *s, int fd);


#endif
