/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvznuzda <pashavznuzdajev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 16:18:15 by pvznuzda          #+#    #+#             */
/*   Updated: 2022/03/28 11:26:08 by pvznuzda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*next_node;

	current = *lst;
	while (current != NULL)
	{
		next_node = current -> next;
		ft_lstdelone(current, del);
		current = next_node;
	}
	*lst = NULL;
}
