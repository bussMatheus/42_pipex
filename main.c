/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mely-pan <mely-pan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 12:58:45 by mely-pan          #+#    #+#             */
/*   Updated: 2025/02/16 20:29:45 by mely-pan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	if (argc < 5)
		error_exit(NULL, "Invalid arguments!");
	if (!check_empty_cmd(argc, argv))
		error_exit(NULL, "Empty cmd!");
	pipex(argc, argv, env);
	return (0);
}
