/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvznuzda <pashavznuzdajev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 19:47:12 by pvznuzda          #+#    #+#             */
/*   Updated: 2022/07/25 18:23:15 by pvznuzda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>
#include "libft/libft.h"
#include "gnl/get_next_line.h"

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

int	check_here_doc(char **argv)
{
	if (!ft_strncmp("here_doc", argv[1], 8))
		return (1);
	return  (0);	
}

int	main(int argc, char **argv, char **envp)
{
	char	**paths;
	char	**cmd_n_args;
	char	*cmd_path;
	int		pipefd[2];
	int		infile;
	int		outfile;
	int		forkid;
	int		i;

	infile = open(argv[1], O_RDONLY);
	outfile = open(argv[argc - 1], O_WRONLY | O_TRUNC);
	paths = get_paths(envp);
	i = 0;
	pipe(pipefd);
	if (check_here_doc(argv))
	{
		i = 2;
		char	*line;
		while (1)
		{
			write(1, "here_doc> ", 10);
			line = get_next_line(0);
			if (line && !ft_strncmp(line, argv[2], ft_strlen(argv[2])) && line[ft_strlen(argv[2])] == '\n')
				break;
			if (line)
				write(pipefd[1], line, ft_strlen(line));
		}
	}
	while (i < argc - 3)
	{
		if (i == 0)
		{
			dup2(infile, 0);
			dup2(pipefd[1], 1);
		}
		else
		{
			close(pipefd[1]);
			dup2(pipefd[0], 0);
			if (i == argc - 4)
				dup2(outfile, 1);
			else
			{
				pipe(pipefd);
				dup2(pipefd[1], 1);
			}
		}
		forkid = fork();
		if (forkid == 0)
		{
			cmd_n_args = get_cmd_n_args(argv[i + 2]);
			cmd_path = get_cmd_path(paths, cmd_n_args[0]);
			cmd_n_args[0] = cmd_path;
			execve(cmd_path, cmd_n_args, 0);
		}
		i++;
	}
	close(infile);
	close(outfile);
	return (0);
}
