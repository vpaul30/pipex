/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvznuzda <pashavznuzdajev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 19:47:12 by pvznuzda          #+#    #+#             */
/*   Updated: 2022/07/30 18:55:33 by pvznuzda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	int		pipefd[2];
	int		i;
	t_vars	vars;
	
	init_vars(argc, argv, envp, &vars);
	if (pipe(pipefd) < 0)
	{
		perror("");
		my_exit(vars, 0);
	}
	close(pipefd[0]);
	if (check_here_doc(argv))
		vars.open_err = is_here_doc(vars, &vars.outfile, &i, pipefd);
	else
		vars.open_err = no_here_doc(vars, &vars.infile, &vars.outfile, &i);
	check_open_err(vars);
	while (i < argc - 3)
	{
		if (set_dups(vars, pipefd, &i))
			my_exit(vars, 1);
		if (fork_n_execve(vars, pipefd, &i))
			my_exit(vars, 1);
	}
	while (wait(0) > 0);
	clear_paths_n_close_files(vars.paths, vars, 1);
	close(pipefd[1]);
	close(pipefd[0]);
	return (0);
}
