/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvznuzda <pashavznuzdajev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:08:27 by pvznuzda          #+#    #+#             */
/*   Updated: 2022/03/26 16:28:29 by pvznuzda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;

	src_len = ft_strlen(src);
	if (dstsize != 0)
	{
		i = 0;
		while (i < dstsize - 1 && i < src_len)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_len);
}
