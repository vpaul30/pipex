/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvznuzda <pashavznuzdajev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:42:23 by pvznuzda          #+#    #+#             */
/*   Updated: 2022/07/28 17:38:50 by pvznuzda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	**get_paths(char **envp)
{
	char	**paths;
	int		i;

	if (!envp || !(*envp))
		return (NULL);
	while (*envp != NULL)
	{
		if (!ft_strncmp("PATH=", *envp, 5))
			break;
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
	int		paths_i;

	paths_i = 0;
	while (paths[paths_i])
	{
		cmd_path = ft_strjoin(paths[paths_i], "/");
		cmd_path = ft_strjoin(cmd_path, cmd);
		if (access(cmd_path, X_OK) == 0)
			return (cmd_path);
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
	i = -1;
	while (envp[++i] != NULL)
	{
		if (!ft_strncmp("SHELL=", envp[i], 6))
			break;
	}
	if (envp[i] == NULL)
		return (NULL);
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
}