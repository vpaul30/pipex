/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvznuzda <pashavznuzdajev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 10:27:25 by pvznuzda          #+#    #+#             */
/*   Updated: 2022/03/27 13:28:29 by pvznuzda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*p;
	size_t			i;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return ((char *)ft_calloc(1, 1));
	if (len > ft_strlen(s))
		p = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	else
		p = (char *)malloc((len + 1) * sizeof(char));
	if (p == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[start + i] != '\0')
	{
		p[i] = s[start + i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
