/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvznuzda <pashavznuzdajev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 11:28:00 by pvznuzda          #+#    #+#             */
/*   Updated: 2022/03/26 16:47:17 by pvznuzda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	n_i;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (i < len && haystack[i] != '\0')
	{
		n_i = 0;
		while ((i + n_i) < len && needle[n_i] == haystack[i + n_i])
		{
			if (needle[n_i + 1] == '\0')
				return ((char *)haystack + i);
			n_i++;
		}
		i++;
	}
	return (NULL);
}
