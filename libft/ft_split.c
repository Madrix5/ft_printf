/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrijime <adrijime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 19:31:18 by adrijime          #+#    #+#             */
/*   Updated: 2024/01/26 20:24:55 by adrijime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**free_me(char **str)
{
	int	i;

	if (str)
	{
		i = 0;
		while (str[i])
		{
			free(str[i]);
			i++;
		}
		free(str);
	}
	return (NULL);
}

static int	ft_count_w(const char *s, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	if (s[0] != c && s[0])
	{
		word++;
		i++;
	}
	while (s[i])
	{
		if (s[i] != c && s[i - 1] == c)
			word++;
		i++;
	}
	return (word);
}

static char	**fill_malloc(const char *s, char **str, char c)
{
	int		i;
	int		j;
	int		start;

	i = 0;
	start = -1;
	j = 0;
	while (j < ft_count_w(s, c))
	{
		if (s[i] != c && start == -1)
			start = i;
		while (s[i] && s[i] != c)
			i++;
		if (start != -1)
		{
			str[j] = ft_substr(s, start, i - start);
			if (!str[j])
				return (free_me(str));
			j++;
			start = -1;
		}
		i++;
	}
	str[j] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;

	str = malloc(sizeof(char *) * (ft_count_w(s, c) + 1));
	if (!str)
		return (NULL);
	str = fill_malloc(s, str, c);
	if (!str)
		return (NULL);
	return (str);
}
