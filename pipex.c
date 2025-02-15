/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mely-pan <mely-pan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 12:57:57 by mely-pan          #+#    #+#             */
/*   Updated: 2025/02/15 14:59:54 by mely-pan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	child_process(t_pipex *pipx, int i)
{
	pid_t	pid;

	if (i < pipx->cmd_count - 1 && pipe(pipx->pipefd) < 0)
		error_exit(pipx, "pipe failed :(");
	pid = fork();
	if (pid < 0)
		error_exit(pipx, "Error forking :(");
	if (pid == 0)
	{
		dup2(pipx->prev_pipe, STDIN_FILENO);
		close(pipx->prev_pipe);
		if (i < pipx->cmd_count - 1)
		{
			dup2(pipx->pipefd[1], STDOUT_FILENO); //* cmds
			close(pipx->pipefd[1]);
			close(pipx->pipefd[0]); // *close pipe reading
		}
		else
		{
			dup2(pipx->outfile, STDOUT_FILENO); //* last cmd
			close(pipx->outfile);
		}
		execute(pipx, pipx->cmds[i], pipx->env);
	}
	return (pid);
}

void	init_pipx(t_pipex *pipx, int argc, char **argv, char **env)
{
	ft_bzero(pipx, sizeof(t_pipex));
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		init_pipex_here_doc(pipx, argc, argv, env);
	else
	{
		pipx->env = env;
		pipx->here_doc = 0;
		pipx->cmd_count = argc - 3;
		pipx->cmds = argv + 2;
		pipx->infile = open(argv[1], O_RDONLY);
		if (pipx->infile < 0)
			error_exit(pipx, "Error opening infile");
		pipx->outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC,
				0644);
		if (pipx->outfile < 0)
			error_exit(pipx, "Error opening outfile");
		pipx->prev_pipe = pipx->infile;
	}
}

void	execute(t_pipex *pipx, char *cmd, char **env)
{
	char	*cmd_path;
	char	**cmd_args;

	cmd_args = ft_split_shell(cmd);
	cmd_path = find_command(cmd_args[0], env);
	if (!cmd_path)
	{
		ft_putstr_fd("Command not found: ", 2);
		ft_putstr_fd(cmd_args[0], 2);
		ft_putstr_fd("\n", 2);
		free_paths(cmd_args);
		error_exit(pipx, "Failure splitting commands");
		//! exit(127);  maybe add flag_exit and add exit(flag_exit) in error_ecit()
	}
	execve(cmd_path, cmd_args, env);
	perror("execve failed");
	free(cmd_path);
	free_paths(cmd_args);
	exit(1);
}

char	*find_command(char *cmd_args, char **env)
{
	char	**paths;
	char	*full_path;
	int		i;
	int		path_len;

	paths = get_paths(env);
	if (!paths)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		path_len = ft_strlen(paths[i]);
		full_path = malloc(sizeof(char) * (path_len + ft_strlen(cmd_args) + 2));
		if (!full_path)
			break ;
		ft_strlcpy(full_path, paths[i], path_len + 1);
		ft_strlcat(full_path, "/", path_len + 2);
		ft_strlcat(full_path, cmd_args, path_len + ft_strlen(cmd_args) + 2);
		if (access(full_path, X_OK) == 0)
			return (free_paths(paths), full_path);
		free(full_path);
		i++;
	}
	free_paths(paths);
	return (NULL);
}

void	pipex(int argc, char **argv, char **env)
{
	t_pipex	pipx;
	pid_t	pid;
	int		i;

	i = 0;
	init_pipx(&pipx, argc, argv, env);
	while (i < pipx.cmd_count)
	{
		pid = child_process(&pipx, i);
		close(pipx.prev_pipe);
		if (i < pipx.cmd_count - 1)
		{
			close(pipx.pipefd[1]);
			pipx.prev_pipe = pipx.pipefd[0];
		}
		i++;
	}
	close(pipx.outfile);
	i = 0;
	while (i < pipx.cmd_count)
	{
		wait(NULL);
		i++;
	}
}
