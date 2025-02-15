/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mely-pan <mely-pan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 12:58:52 by mely-pan          #+#    #+#             */
/*   Updated: 2025/02/15 13:08:08 by mely-pan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	handle_here_doc(t_pipex *pipx, char *limiter)
{
	char	*line;
	int		pipefd[2];

	if (pipe(pipefd) < 0)
		error_exit(pipx, "error creating pipe");
	pipx->prev_pipe = pipefd[0];
	write(1, "here_doc> ", 10);
	line = get_next_line(0);
	while (line != NULL)
	{
		if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0
			&& line[ft_strlen(limiter)] == '\n')
		{
			free(line);
			break ;
		}
		write(pipefd[1], line, ft_strlen(line));
		free(line);
		write(1, "here_doc> ", 10);
		line = get_next_line(0);
	}
	close(pipefd[1]);
}

void	init_pipex_here_doc(t_pipex *pipx, int argc, char **argv, char **env)
{
	pipx->cmd_count = argc - 4;
	pipx->cmds = argv + 3;
	pipx->env = env;
	pipx->infile = 0;
	pipx->here_doc = 1;
	handle_here_doc(pipx, argv[2]);
	pipx->outfile = open(argv[argc - 1], O_CREAT | O_WRONLY | O_APPEND, 0644);
	// *0644 is the permission if we are creating a file
	if (pipx->outfile < 0)
		error_exit(pipx, "Error opening / creating outfile");
}
