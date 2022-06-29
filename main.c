/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvznuzda <pashavznuzdajev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 19:47:12 by pvznuzda          #+#    #+#             */
/*   Updated: 2022/06/29 16:03:58 by pvznuzda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"

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
		{
			
			printf("Path found: %s\n", cmd_path);
			return (cmd_path);
		}		
		paths_i++;
	}
	printf("Path not found\n");
	return (NULL);
}

int	main(int argc, char **argv, char **envp)
{
	char	**paths;
	char	*cmd_path;
	int		pipefd[2];

	if (pipe(pipefd) < 0)
		return (0);
	paths = get_paths(envp);
	cmd_path = get_cmd_path(paths, "cat");
	execve(cmd_path, argv, 0);	
	return (0);
}
