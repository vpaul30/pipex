/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvznuzda <pashavznuzdajev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 19:47:12 by pvznuzda          #+#    #+#             */
/*   Updated: 2022/11/02 20:15:40 by pvznuzda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	clear_paths_n_close_files(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->paths[i])
	{
		free(vars->paths[i]);
		i++;
	}
	free(vars->paths);
	if (vars->pipefd[0] != -1)
		close(vars->pipefd[0]);
	if (vars->pipefd[1] != -1)
		close(vars->pipefd[1]);
	if (vars->outfile >= 0)
		close(vars->outfile);
	dup2(vars->saved_stdin, 0);
	close(vars->saved_stdin);
	dup2(vars->saved_stdout, 1);
	close(vars->saved_stdout);
	while (wait(0) > 0)
		;
}

void	my_exit(t_vars *vars)
{
	clear_paths_n_close_files(vars);
	exit (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_vars	vars;

	if (argc != 5)
		return (0);
	init_vars(argc, argv, envp, &vars);
	my_pipe(&vars);
	no_here_doc(&vars);
	while (vars.i < argc - 3)
	{
		if (set_dups(&vars))
			my_exit(&vars);
		if (fork_n_execve(&vars))
			my_exit(&vars);
	}
	clear_paths_n_close_files(&vars);
	return (0);
}
