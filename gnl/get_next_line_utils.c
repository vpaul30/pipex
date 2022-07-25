/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvznuzda <pashavznuzdajev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 12:04:18 by pvznuzda          #+#    #+#             */
/*   Updated: 2022/06/25 12:48:07 by pvznuzda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup_gnl(char *str, int nl)
{
	char	*res;
	int		len;

	if (!str)
		return (NULL);
	len = 0;
	while (str[len] != '\0')
		len++;
	res = malloc(sizeof(char) * (len + nl + 1));
	if (!res)
		return (NULL);
	len = -1;
	while (str[++len] != '\0')
		res[len] = str[len];
	if (nl)
	{
		res[len] = '\n';
		len++;
	}
	res[len] = '\0';
	return (res);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*res;
	int		s1_len;
	int		s2_len;

	if (!s1)
		return (ft_strdup_gnl(s2, 0));
	if (!s2)
		return (ft_strdup_gnl(s1, 0));
	s1_len = 0;
	while (s1[s1_len] != '\0')
		s1_len++;
	s2_len = 0;
	while (s2[s2_len] != '\0')
		s2_len++;
	res = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!res)
		return (NULL);
	s1_len = -1;
	while (s1[++s1_len] != '\0')
		res[s1_len] = s1[s1_len];
	s2_len = -1;
	while (s2[++s2_len] != '\0')
		res[s1_len + s2_len] = s2[s2_len];
	res[s1_len + s2_len] = '\0';
	return (res);
}

int	read_to_buffer(char buffer[], int fd)
{
	int	b_read;

	b_read = read(fd, buffer, BUFFER_SIZE);
	buffer[b_read] = '\0';
	return (b_read);
}

char	*check_buffer_nl(char buffer[], char *result, char **rem, int nl_n_i[])
{
	char	*res;
	char	*temp;
	int		i;

	i = -1;
	while (buffer[++i] != '\0')
	{
		if (buffer[i] == '\n')
		{
			nl_n_i[0] = 1;
			buffer[i] = '\0';
			temp = ft_strdup_gnl(buffer, 1);
			res = ft_strjoin_gnl(result, temp);
			free(result);
			free(temp);
			temp = ft_strdup_gnl(buffer + i + 1, 0);
			free(*rem);
			*rem = temp;
			return (res);
		}
	}
	res = ft_strjoin_gnl(result, buffer);
	free(result);
	return (res);
}

char	*check_remainder_nl(char *result, char **rem, int nl_n_i[])
{
	char	*res;
	char	*temp;

	while ((*rem)[++nl_n_i[1]] != '\0')
	{
		if ((*rem)[nl_n_i[1]] == '\n')
		{
			nl_n_i[0] = 1;
			(*rem)[nl_n_i[1]] = '\0';
			temp = ft_strdup_gnl(*rem, 1);
			res = ft_strjoin_gnl(result, temp);
			free(result);
			free(temp);
			temp = ft_strdup_gnl((*rem) + nl_n_i[1] + 1, 0);
			free(*rem);
			*rem = temp;
			return (res);
		}
	}
	res = ft_strjoin_gnl(result, *rem);
	free(result);
	free(*rem);
	*rem = NULL;
	return (res);
}
