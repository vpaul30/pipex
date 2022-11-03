/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvznuzda <pashavznuzdajev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 17:15:36 by pvznuzda          #+#    #+#             */
/*   Updated: 2022/11/02 20:22:07 by pvznuzda         ###   ########.fr       */
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

int	check_cmd_path(char **argv, char **paths, int *i)
{
	char	**cmd_n_args;
	char	*cmd_path;
	int		k;

	cmd_n_args = get_cmd_n_args(argv[(*i) + 2]);
	cmd_path = get_cmd_path(paths, cmd_n_args[0]);
	k = -1;
	while (cmd_n_args[++k])
		free(cmd_n_args[k]);
	free(cmd_n_args);
	if (cmd_path == NULL)
		return (1);
	free(cmd_path);
	return (0);
}

void	my_pipe(t_vars *vars)
{
	if (pipe(vars->pipefd) < 0)
	{
		perror("Error:");
		my_exit(vars);
	}
}
