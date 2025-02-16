/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mely-pan <mely-pan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 12:57:52 by mely-pan          #+#    #+#             */
/*   Updated: 2025/02/16 20:25:16 by mely-pan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex.h"

char	**get_paths(char **env)
{
	int		i;
	char	*path_var;
	char	**paths;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			path_var = env[i] + 5;
			paths = ft_split(path_var, ':');
			return (paths);
		}
		i++;
	}
	return (NULL);
}

int	check_empty_cmd(int argc, char **argv)
{
	int	i;

	i = 2;
	while (i < argc - 1)
	{
		if (argv[i][0] == 0)
			return (0);
		i++;
	}
	return (1);
}
