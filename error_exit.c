/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mely-pan <mely-pan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 12:59:03 by mely-pan          #+#    #+#             */
/*   Updated: 2025/02/15 15:00:48 by mely-pan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_exit(t_pipex *pipx, char *s)
{
	ft_putstr_fd(s, 2);
	if (pipx)
	{
		if (pipx->infile >= 0)
			close(pipx->infile);
		if (pipx->outfile >= 0)
			close(pipx->outfile);
		if (pipx->prev_pipe >= 0)
			close(pipx->prev_pipe);
		if (pipx->pipefd[0] >= 0)
			close(pipx->pipefd[0]);
		if (pipx->pipefd[1] >= 0)
			close(pipx->pipefd[1]);
	}
	exit(1);
}

void	free_paths(char **paths)
{
	int i;

	i = 0;
	if (paths)
	{
		while (paths[i])
			free(paths[i++]);
		free(paths);
	}
}