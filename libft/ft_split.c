/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvznuzda <pashavznuzdajev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 11:24:33 by pvznuzda          #+#    #+#             */
/*   Updated: 2022/03/28 12:57:25 by pvznuzda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	counter;
	int	i;

	counter = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			counter++;
		i++;
	}
	return (counter);
}

static unsigned int	gs(char const *s, char c, int endi)
{
	unsigned int	starti;

	starti = endi;
	while (starti != 0 && s[starti - 1] != c)
		starti--;
	return (starti);
}

char	**ft_split(char const *s, char c)
{
	char				**r;
	int					words;
	unsigned int		i;
	int					w_i;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	r = (char **)malloc((words + 1) * sizeof(char *));
	if (r == NULL)
		return (NULL);
	i = 0;
	w_i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			r[w_i] = ft_substr(s, gs(s, c, i), (size_t)(i + 1 - gs(s, c, i)));
			w_i++;
		}
		i++;
	}
	r[w_i] = NULL;
	return (r);
}
