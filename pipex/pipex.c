/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudar <hboudar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 20:03:09 by hboudar           #+#    #+#             */
/*   Updated: 2024/02/27 23:30:05 by hboudar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char *av[], char *env[])
{
	int	fd[2];
	int	pid;

	if (ac != 5)
	{
		write(2, "Error: Invalid number of arguments\n", 35);
		return (1);
	}
	if (pipe(fd) == -1)
		error("Pipe");
	pid = fork();
	if (pid == -1)
		error("Fork");
	if (pid == 0)
		first_process(av, env, fd);
	else
	{
		check_files(close(fd[1]), dup2(fd[0], 0), close(fd[0]));
		last_process(ac, av, env);
	}
	wait(NULL);
}
