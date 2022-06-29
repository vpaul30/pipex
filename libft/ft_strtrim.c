/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvznuzda <pashavznuzdajev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 10:56:10 by pvznuzda          #+#    #+#             */
/*   Updated: 2022/03/28 12:58:07 by pvznuzda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_char_in_set(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	s1_len;
	unsigned int	start_i;
	unsigned int	end_i;
	char			*p;

	if (!s1)
		return (NULL);
	s1_len = ft_strlen(s1);
	if (!s1_len)
		return ((char *)ft_calloc(1, 1));
	start_i = 0;
	while (start_i < s1_len && ft_char_in_set(s1[start_i], set))
		start_i++;
	end_i = s1_len - 1;
	while (end_i > 0 && ft_char_in_set(s1[end_i], set))
		end_i--;
	p = ft_substr(s1, start_i, end_i - start_i + 1);
	return (p);
}
