/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvznuzda <pashavznuzdajev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 12:04:07 by pvznuzda          #+#    #+#             */
/*   Updated: 2022/04/03 12:35:39 by pvznuzda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	char		*result;
	static char	*remainder;
	int			nl_n_i[2];

	if (BUFFER_SIZE < 1 || (read(fd, NULL, 0) < 0))
		return (NULL);
	result = NULL;
	nl_n_i[0] = 0;
	nl_n_i[1] = -1;
	while (!nl_n_i[0])
	{
		if (remainder && (remainder[0] == '\0'))
		{
			free(remainder);
			remainder = NULL;
		}
		if (remainder)
			result = check_remainder_nl(result, &remainder, nl_n_i);
		else if ((read_to_buffer(buffer, fd) == 0))
			return (result);
		else
			result = check_buffer_nl(buffer, result, &remainder, nl_n_i);
	}
	return (result);
}
