/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrijime <adrijime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 19:31:15 by adrijime          #+#    #+#             */
/*   Updated: 2024/01/26 20:25:27 by adrijime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	len = ft_strlen(s1) - 1;
	while (i <= len && ft_strchr(set, s1[i]))
		i++;
	if (i > len || !s1 || !set)
		return (ft_strdup(""));
	while (len > i && ft_strchr(set, s1[len]))
		len--;
	str = ft_substr(s1, i, len - i + 1);
	if (!str)
		return (NULL);
	return (str);
}
