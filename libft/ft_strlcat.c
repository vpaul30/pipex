/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvznuzda <pashavznuzdajev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 20:56:43 by pvznuzda          #+#    #+#             */
/*   Updated: 2022/03/26 14:49:33 by pvznuzda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dstsize <= dst_len)
		return (src_len + dstsize);
	i = 0;
	if (dstsize != 0)
	{
		while (dst_len + i < dstsize - 1 && i < src_len)
		{
			dst[dst_len + i] = src[i];
			i++;
		}
		dst[i + dst_len] = '\0';
	}
	return (dst_len + src_len);
}
