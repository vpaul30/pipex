/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvznuzda <pashavznuzdajev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 20:40:58 by pvznuzda          #+#    #+#             */
/*   Updated: 2022/03/26 16:48:02 by pvznuzda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		str_len;

	str_len = ft_strlen(s);
	if (s[str_len] == '\0' && c == '\0')
		return ((char *)(s + str_len));
	while (str_len >= 0)
	{
		if (s[str_len] == (char)c)
			return ((char *)(s + str_len));
		str_len--;
	}
	return (NULL);
}
