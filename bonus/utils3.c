/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvznuzda <pashavznuzdajev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 17:15:36 by pvznuzda          #+#    #+#             */
/*   Updated: 2022/07/29 13:44:00 by pvznuzda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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

void	check_open_err(t_vars vars)
{
	if (vars.open_err)
	{
		if (vars.open_err == 2)
			my_exit(vars, 2);
		else
			my_exit(vars, 0);	
	}
}

// void	print_cmd_error()
// {
// 	char	*shellname;

// 	shellname = get_shellname(envp);
// }