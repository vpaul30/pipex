/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvznuzda <pashavznuzdajev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 12:04:25 by pvznuzda          #+#    #+#             */
/*   Updated: 2022/06/25 13:54:26 by pvznuzda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define BUFFER_SIZE 10

char	*get_next_line(int fd);
char	*ft_strdup_gnl(char *str, int nl);
char	*ft_strjoin_gnl(char *s1, char *s2);
int		read_to_buffer(char buffer[], int fd);
char	*check_buffer_nl(char buffer[], char *result, char **rem, int nl_n_i[]);
char	*check_remainder_nl(char *result, char **rem, int nl_n_i[]);

#endif