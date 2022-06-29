/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvznuzda <pashavznuzdajev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 09:48:57 by pvznuzda          #+#    #+#             */
/*   Updated: 2022/03/26 17:30:01 by pvznuzda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*p;
	int		s_len;
	int		i;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	p = malloc((s_len + 1) * sizeof(char));
	if (p == NULL)
		return (NULL);
	i = 0;
	while (i < s_len)
	{
		p[i] = (*f)(i, s[i]);
		i++;
	}
	p[i] = '\0';
	return (p);
}
