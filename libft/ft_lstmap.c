/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrijime <adrijime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 20:48:56 by adrijime          #+#    #+#             */
/*   Updated: 2024/01/27 18:21:37 by adrijime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	void	*aux;
	t_list	*newlist;
	t_list	*elem;

	if (!lst)
		return (0);
	newlist = NULL;
	while (lst)
	{
		aux = f(lst->content);
		elem = ft_lstnew(aux);
		if (!elem)
		{
			del(aux);
			ft_lstclear(&newlist, del);
		}
		ft_lstadd_back(&newlist, elem);
		lst = lst->next;
	}
	return (newlist);
}
