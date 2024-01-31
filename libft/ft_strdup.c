/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrijime <adrijime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:35:25 by adrijime          #+#    #+#             */
/*   Updated: 2024/01/30 16:15:41 by adrijime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		s1len;
	int		i;
	char	*nstr;

	i = 0;
	s1len = ft_strlen(s1);
	nstr = malloc((sizeof (char) * (s1len + 1)));
	if (!nstr)
		return (0);
	while (i < s1len + 1)
	{
		nstr[i] = s1[i];
		i++;
	}
	return (nstr);
}

int	main(void)
{
	char	*s1;
	
	s1 = "Hola";
	printf("%s\n", ft_strdup(s1));
}
