/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvznuzda <pashavznuzdajev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:41:14 by pvznuzda          #+#    #+#             */
/*   Updated: 2022/11/02 20:21:24 by pvznuzda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <errno.h>
# include <string.h>
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"

typedef struct s_vars
{
	int		argc;
	char	**argv;
	char	**envp;
	int		infile;
	int		outfile;
	char	**paths;
	int		here_doc;
	int		saved_stdin;
	int		saved_stdout;
	int		pipefd[2];
	int		i;
}	t_vars;

int		check_here_doc(char **argv);
int		is_here_doc(t_vars *vars);
int		no_here_doc(t_vars *vars);
char	**get_paths(char **envp);
char	**get_cmd_n_args(char *cmd);
char	*get_cmd_path(char **paths, char *cmd);
char	*get_shellname(char **envp);
void	init_vars(int argc, char **argv, char **envp, t_vars *vars);
void	file_error(int argc, char **argv, char **envp, int file);
int		fork_n_execve(t_vars *vars);
int		set_dups(t_vars *vars);
void	clear_paths_n_close_files(t_vars *vars);
void	my_exit(t_vars *vars);
char	*get_nothing(void);
int		check_cmd_path(char **argv, char **paths, int *i);
void	my_pipe(t_vars *vars);

#endif