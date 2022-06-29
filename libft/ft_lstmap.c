/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvznuzda <pashavznuzdajev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 16:47:18 by pvznuzda          #+#    #+#             */
/*   Updated: 2022/03/28 12:22:43 by pvznuzda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_lst_head;

	if (!lst)
		return (NULL);
	new_lst = ft_lstnew(f(lst -> content));
	if (new_lst == NULL)
		return (NULL);
	new_lst_head = new_lst;
	while (lst -> next != NULL)
	{
		lst = lst -> next;
		new_lst -> next = ft_lstnew(f(lst -> content));
		new_lst = new_lst -> next;
		if (new_lst == NULL)
			ft_lstclear(&new_lst_head, del);
	}
	return (new_lst_head);
}
