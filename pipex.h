/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mely-pan <mely-pan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 12:57:42 by mely-pan          #+#    #+#             */
/*   Updated: 2025/02/15 12:59:09 by mely-pan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./libft/libft.h"
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_pipex
{
	int		infile;
	int		outfile;
	int		prev_pipe;
	int		pipefd[2];
	int		cmd_count;
	int		here_doc;
	char	*limiter;
	char	**env;
	char	**cmds;
}			t_pipex;

void		error_exit(t_pipex *pipx, char *s);
void		free_paths(char **paths);

char		*find_command(char *cmd_args, char **env);
char		**get_paths(char **env);
void		pipex(int argc, char **argv, char **env);
void		execute(t_pipex *pipx, char *cmd, char **env);
void		init_pipex_here_doc(t_pipex *pipx, int argc, char **argv,
				char **env);

#endif