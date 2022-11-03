/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvznuzda <pashavznuzdajev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:39:18 by pvznuzda          #+#    #+#             */
/*   Updated: 2022/11/02 20:17:11 by pvznuzda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_here_doc(char **argv)
{
	if (!ft_strncmp("here_doc", argv[1], 8) && argv[1][8] == '\0')
		return (1);
	return (0);
}

int	no_here_doc(t_vars *vars)
{
	char	*line;

	vars->infile = open(vars->argv[1], O_RDONLY);
	if (vars->infile < 0)
		file_error(vars->argc, vars->argv, vars->envp, 0);
	vars->outfile = open(vars->argv[vars->argc - 1],
			O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (vars->outfile < 0)
		file_error(vars->argc, vars->argv, vars->envp, 1);
	while (vars->infile >= 0)
	{
		line = get_next_line(vars->infile);
		if (!line)
			break ;
		write(vars->pipefd[1], line, ft_strlen(line));
		free(line);
	}
	close(vars->pipefd[1]);
	if (vars->infile >= 0)
		close(vars->infile);
	return (0);
}
