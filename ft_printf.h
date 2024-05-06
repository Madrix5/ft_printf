/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrijime <adrijime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:01:09 by adrijime          #+#    #+#             */
/*   Updated: 2024/05/06 16:01:10 by adrijime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int	ft_putchar(char c, int *count);
int	ft_putstr(char *str, int *count);
int	ft_putnbr_base(long int n, int *count, int base, char flag);
int	ft_putnbr_ptr(unsigned long n, int *count, unsigned long base, char flag);
int	dif_letter(char dif, va_list ap, int *count);
int	ft_printf(const char *str, ...);

#endif