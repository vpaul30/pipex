/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvznuzda <pashavznuzdajev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:45:31 by pvznuzda          #+#    #+#             */
/*   Updated: 2022/07/30 18:58:07 by pvznuzda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	file_error(int argc, char **argv, char **envp, int file)
{
	char	*shellname;
	char	*result_line;
	char	*temp;

	temp = get_shellname(envp);
	result_line = ft_strjoin(temp, ": ");
	free(temp);
	temp = ft_strjoin(result_line, strerror(errno));
	free(result_line);
	result_line = ft_strjoin(temp, ": ");
	free(temp);
	if (file == 0)
		temp = ft_strjoin(result_line, argv[1]);
	else
		temp = ft_strjoin(result_line, argv[argc - 1]);
	free(result_line);
	result_line = ft_strjoin(temp, "\n");
	free(temp);
	write(2, result_line, ft_strlen(result_line));
	free(result_line);
}

int	fork_n_execve(t_vars vars, int pipefd[2], int *i)
{
	char	**cmd_n_args;
	char	*cmd_path;
	int		forkid;
	int		j;

	forkid = fork();
	if (forkid < 0)
	{
		perror("Error: ");
		return (1);
	}
	if (forkid == 0)
	{
		if (*i == 0 && vars.infile == 0)
		{
			close(pipefd[0]);
			close(pipefd[1]);
			clear_paths_n_close_files(vars.paths, vars, 0);
			exit (0);
		}
		cmd_n_args = get_cmd_n_args(vars.argv[(*i) + 2]);
		cmd_path = get_cmd_path(vars.paths, cmd_n_args[0]);
		if (!cmd_path)
		{
			j = -1;
			while (cmd_n_args[++j])
				free(cmd_n_args[j]);
			free(cmd_n_args);
			close(pipefd[0]);
			close(pipefd[1]);
			clear_paths_n_close_files(vars.paths, vars, 0);
			write(2, "cmd error\n", 10);
			exit (0);
		}
		else
			execve(cmd_path, cmd_n_args, 0);
	}
	else
		wait(NULL); // REMOVE
		write(2, "\nhere\n", 6);
		*i = *i + 1;
	return (0);
}

int	set_dups(t_vars vars, int pipefd[2], int *i)
{
	if (*i == 0 && *i == vars.argc - 4)
	{
		if (vars.infile == 0)
			dup2(pipefd[0], 0);
		else
			dup2(vars.infile, 0);
		dup2(vars.outfile, 1);
	}
	else if (*i == 0)
	{
		if (vars.infile == 0)
			dup2(pipefd[0], 0);
		else
			dup2(vars.infile, 0);
		dup2(pipefd[1], 1);
	}
	else
	{
		close(pipefd[1]);
		dup2(pipefd[0], 0);
		if (*i == vars.argc - 4)
			dup2(vars.outfile, 1);
		else
		{
			if (pipe(pipefd) < 0)
			{
				perror("Error: ");
				return (1);
			}
			dup2(pipefd[1], 1);
		}
	}
	return (0);
}

void	clear_paths_n_close_files(char **paths, t_vars vars, int close_files)
{
	int	i;
	
	i = 0;
	while (paths[i])
	{
		free(paths[i]);
		i++;
	}
	free(paths);
	if (close_files == 1)
	{
		if (vars.infile != 0)
			close(vars.infile);
		close(vars.outfile);
	}
	else if (close_files == 2)
		close(vars.infile);
}

void	my_exit(t_vars vars, int close_files)
{
	clear_paths_n_close_files(vars.paths, vars, close_files);
	exit (0);
}
