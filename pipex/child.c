/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudar <hboudar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 20:03:00 by hboudar           #+#    #+#             */
/*   Updated: 2024/02/27 23:51:58 by hboudar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_process(char *av[], char *envp[], int fd[2])
{
	int	infile;

	infile = open(av[1], O_RDONLY);
	if (infile == -1)
		error("infile");
	check_files(dup2(infile, 0), close(fd[0]), dup2(fd[1], 1));
	check_files(close(infile), 0, 0);
	execute(av[2], envp, -1);
}

void	last_process(int ac, char *av[], char *env[])
{
	int	outfile;
	int	pid;

	outfile = open(av[ac - 1], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (outfile == -1)
		error("outfile");
	pid = fork();
	if (pid == -1)
		error("Fork");
	if (pid == 0)
	{
		check_files(dup2(outfile, 1), close(outfile), 0);
		execute(av[ac - 2], env, -1);
	}
	else
		check_files(close(outfile), 0, 0);
}
