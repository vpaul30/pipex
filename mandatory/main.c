/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvznuzda <pashavznuzdajev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 19:47:12 by pvznuzda          #+#    #+#             */
/*   Updated: 2022/07/28 17:01:53 by pvznuzda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

void	check_args_amount(int argc)
{
	if (argc != 4)
	{
		write(1, "Wrong amount of arguments!\n", 28);
		exit (0);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int		pipefd[2];
	int		i;
	t_vars	vars;
	
	check_args_amount(argc);
	init_vars(argc, argv, envp, &vars);
	if (pipe(pipefd) < 0)
	{
		strerror(errno);
		my_exit(vars, 0);
	}
	vars.open_err = no_here_doc(vars, &vars.infile, &vars.outfile, &i);
	check_open_err(vars);
	while (i < argc - 3)
	{
		if (set_dups(vars, pipefd, &i))
			my_exit(vars, 1);
		if (fork_n_execve(vars.argv, vars.paths, &i))
			my_exit(vars, 1);
	}
	while (wait(0) > 0);
	clear_paths_n_close_files(vars.paths, vars, 1);
	return (0);
}
