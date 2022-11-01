/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvznuzda <pashavznuzdajev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 17:15:36 by pvznuzda          #+#    #+#             */
/*   Updated: 2022/07/29 11:45:42 by pvznuzda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_nothing(void)
{
	char	*result;
	
	result = malloc(3);
	if (!result)
		return (NULL);
	result[0] = '?';
	result[1] = '?';
	result[2] = '\0';
	return (result);
}