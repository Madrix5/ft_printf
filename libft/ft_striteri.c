/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrijime <adrijime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 19:31:25 by adrijime          #+#    #+#             */
/*   Updated: 2024/01/30 16:18:51 by adrijime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	f(int i, char *s)
{
	s[i] = s[i] + i;
}

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int		i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
	return ;
}

int	main(void)
{
	char *s;
	
	s = "Hola";
	ft_striteri(s, f);
	printf("%s\n", s);
}
