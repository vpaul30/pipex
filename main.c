/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvznuzda <pashavznuzdajev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 19:47:12 by pvznuzda          #+#    #+#             */
/*   Updated: 2022/06/30 15:59:07 by pvznuzda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
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
	int		pipefd1[2];
	int		infile;
	int		outfile;
	int		f;

	infile = open(argv[1], O_RDONLY);
	outfile = open(argv[2], O_WRONLY, O_TRUNC);
	dup2(infile, 0);
	if (pipe(pipefd1) < 0)
		return (0);

	f = fork();
	if (f == 0)
	{
		close(pipefd1[0]);
		dup2(pipefd1[1], 1);
		paths = get_paths(envp);
		cmd_path = get_cmd_path(paths, "cat");
		execve(cmd_path, NULL, NULL);
	}
	f = fork();
	if (f == 0)
	{
		close(pipefd1[1]);
		char	*args[3];
		args[0] = "/usr/bin/grep";
		args[1] = "line";
		args[2] = NULL;
		dup2(pipefd1[0], 0);
		dup2(outfile, 1);
		execve("/usr/bin/grep", args, 0);
		
	}
	return (0);
}
