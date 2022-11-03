/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvznuzda <pashavznuzdajev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:45:31 by pvznuzda          #+#    #+#             */
/*   Updated: 2022/11/02 19:22:30 by pvznuzda         ###   ########.fr       */
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

void	child_process(t_vars *vars, char **cmd_n_args, char *cmd_path)
{
	int	j;

	close(vars->pipefd[0]);
	close(vars->saved_stdin);
	close(vars->saved_stdout);
	cmd_n_args = get_cmd_n_args(vars->argv[(vars->i) + vars->here_doc + 2]);
	cmd_path = get_cmd_path(vars->paths, cmd_n_args[0]);
	if (!cmd_path)
	{
		j = -1;
		while (cmd_n_args[++j])
			free(cmd_n_args[j]);
		free(cmd_n_args);
		close(vars->pipefd[0]);
		close(vars->pipefd[1]);
		clear_paths_n_close_files(vars);
		write(2, "command not found\n", 19);
		exit (0);
	}
	else
		execve(cmd_path, cmd_n_args, 0);
}

int	fork_n_execve(t_vars *vars)
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
		child_process(vars, cmd_n_args, cmd_path);
	else
		vars->i = vars->i + 1;
	return (0);
}

int	set_dups(t_vars *vars)
{
	dup2(vars->pipefd[0], 0);
	close(vars->pipefd[0]);
	if (vars->i == vars->argc - 4 - vars->here_doc && vars->outfile >= 0)
	{
		dup2(vars->outfile, 1);
		close(vars->outfile);
	}
	else
	{
		my_pipe(vars);
		dup2(vars->pipefd[1], 1);
		close(vars->pipefd[1]);
	}
	return (0);
}
