/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhershel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 21:18:54 by yhershel          #+#    #+#             */
/*   Updated: 2020/06/09 20:33:22 by yhershel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*tmp;

	if (!lst)
		return (NULL);
	if (!(tmp = ft_lstnew(f(lst->content))))
		return (NULL);
	new_lst = tmp;
	while (lst)
	{
		if (lst->next)
		{
			if (!(tmp->next = ft_lstnew(f(lst->next->content))))
			{
				ft_lstclear(&new_lst, del);
				return (NULL);
			}
			tmp = tmp->next;
		}
		lst = lst->next;
	}
	tmp->next = NULL;
	return (new_lst);
}
