/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvznuzda <pashavznuzdajev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:39:18 by pvznuzda          #+#    #+#             */
/*   Updated: 2022/11/02 19:27:19 by pvznuzda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	check_here_doc(char **argv)
{
	if (!ft_strncmp("here_doc", argv[1], 8) && argv[1][8] == '\0')
		return (1);
	return (0);
}

int	is_here_doc(t_vars *vars)
{
	char	*line;
	int		len;

	len = ft_strlen(vars->argv[2]);
	while (1)
	{
		write(1, "pipe here_doc> ", 15);
		line = get_next_line(0);
		if (line && (!ft_strncmp(line, vars->argv[2], len)
				&& line[len] == '\n'))
		{
			free(line);
			break ;
		}
		write(vars->pipefd[1], line, ft_strlen(line));
		free(line);
	}
	vars->outfile = open(vars->argv[vars->argc - 1],
			O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (vars->outfile < 0)
		file_error(vars->argc, vars->argv, vars->envp, 1);
	close(vars->pipefd[1]);
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
