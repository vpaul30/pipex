/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvznuzda <pashavznuzdajev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:06:36 by pvznuzda          #+#    #+#             */
/*   Updated: 2022/04/20 17:51:46 by pvznuzda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;
	size_t	i;

	p = malloc(count * size);
	if (!p)
		return (NULL);
	i = 0;
	while (i < count * size)
	{
		*((char *)(p + i)) = 0;
		i++;
	}
	return (p);
}
