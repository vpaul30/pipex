/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvznuzda <pashavznuzdajev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:42:23 by pvznuzda          #+#    #+#             */
/*   Updated: 2022/11/02 20:17:07 by pvznuzda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_paths(char **envp)
{
	char	**paths;
	int		i;

	if (!envp || !(*envp))
		return (NULL);
	while (*envp != NULL)
	{
		if (!ft_strncmp("PATH=", *envp, 5))
			break ;
		envp++;
	}
	*envp += 5;
	paths = ft_split(*envp, ':');
	return (paths);
}

char	**get_cmd_n_args(char *cmd)
{
	char	**cmd_n_args;

	cmd_n_args = ft_split(cmd, ' ');
	return (cmd_n_args);
}

char	*get_cmd_path(char **paths, char *cmd)
{
	char	*cmd_path;
	char	*temp;
	int		paths_i;

	paths_i = 0;
	while (paths[paths_i])
	{
		temp = ft_strjoin(paths[paths_i], "/");
		cmd_path = ft_strjoin(temp, cmd);
		free(temp);
		if (access(cmd_path, X_OK) == 0)
			return (cmd_path);
		free(cmd_path);
		paths_i++;
	}
	return (NULL);
}

char	*get_shellname(char **envp)
{
	char	**shellpath;
	char	*shellname;
	int		i;

	if (!envp || !(*envp))
		return (NULL);
	i = 0;
	while (envp[i] != NULL)
	{
		if (!ft_strncmp("SHELL=", envp[i], 6))
			break ;
		i++;
	}
	if (envp[i] == NULL)
		return (get_nothing());
	shellpath = ft_split(envp[i], '/');
	i = -1;
	while (shellpath[++i] && shellpath[i + 1] != NULL)
		free(shellpath[i]);
	shellname = ft_strdup(shellpath[i]);
	free(shellpath[i]);
	free(shellpath);
	return (shellname);
}

void	init_vars(int argc, char **argv, char **envp, t_vars *vars)
{
	vars->argc = argc;
	vars->argv = argv;
	vars->envp = envp;
	vars->paths = get_paths(envp);
	vars->saved_stdin = dup(0);
	vars->saved_stdout = dup(1);
	vars->pipefd[0] = -1;
	vars->pipefd[1] = -1;
	vars->i = 0;
}
