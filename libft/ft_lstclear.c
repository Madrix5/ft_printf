/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrijime <adrijime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 20:51:01 by adrijime          #+#    #+#             */
/*   Updated: 2024/01/26 20:51:25 by adrijime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*c_temp;

	if (!lst)
		return ;
	else
	{
		while (*lst)
		{
			c_temp = (*lst)->next;
			ft_lstdelone(*lst, del);
			(*lst) = c_temp;
		}
	}
}
