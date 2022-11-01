/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvznuzda <pashavznuzdajev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:41:14 by pvznuzda          #+#    #+#             */
/*   Updated: 2022/07/28 16:21:37 by pvznuzda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS
# define PIPEX_BONUS

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
	int		open_err;
}	t_vars;

int		check_here_doc(char **argv);
int		is_here_doc(t_vars vars, int *outfile, int *i, int pipefd[2]);
int		no_here_doc(t_vars vars, int *infile, int *outfile, int *i);
char	**get_paths(char **envp);
char	**get_cmd_n_args(char *cmd);
char	*get_cmd_path(char **paths, char *cmd);
char	*get_shellname(char **envp);
void	init_vars(int argc, char **argv, char **envp, t_vars *vars);
void	file_error(int argc, char **argv, char **envp, int file);
int		fork_n_execve(char **argv, char **paths, int *i);
int		set_dups(t_vars vars, int pipefd[2], int *i);
void	clear_paths_n_close_files(char **paths, t_vars vars, int close_files);
void	my_exit(t_vars vars, int close_files);

#endif