/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvznuzda <pashavznuzdajev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:00:20 by pvznuzda          #+#    #+#             */
/*   Updated: 2022/03/28 12:55:59 by pvznuzda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_strrev(char *p)
{
	int		len;
	int		i;
	char	temp;

	i = 0;
	len = 0;
	while (p[len] != '\0')
		len++;
	while (i < len / 2)
	{
		temp = p[i];
		p[i] = p[len - 1 - i];
		p[len - i - 1] = temp;
		i++;
	}
}

static int	ft_abs_itoa(int number)
{
	if (number < 0)
		return (number * -1);
	return (number);
}

static void	get_len_negative(int *len, int *negative, int number)
{
	if (number < 0)
		*negative = 1;
	while (number / 10 != 0)
	{
		number /= 10;
		*len = *len + 1;
	}
}

static void	init_var(int *number_len, int *negative, int *i)
{
	*number_len = 1;
	*negative = 0;
	*i = 0;
}

char	*ft_itoa(int number)
{
	char	*p;
	int		number_len;
	int		negative;
	int		i;

	init_var(&number_len, &negative, &i);
	get_len_negative(&number_len, &negative, number);
	p = malloc((number_len + negative + 1) * sizeof(char));
	if (p == NULL)
		return (NULL);
	while (i < number_len)
	{
		p[i] = ft_abs_itoa(number % 10) + '0';
		number /= 10;
		i++;
	}
	if (negative)
	{
		p[i] = '-';
		p[i + 1] = '\0';
	}
	else
		p[i] = '\0';
	ft_strrev(p);
	return (p);
}
