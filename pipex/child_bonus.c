/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudar <hboudar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:59:47 by hboudar           #+#    #+#             */
/*   Updated: 2024/02/27 23:50:59 by hboudar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	first_process(char *av[], char *envp[], t_pipex *pi)
{
	if (pipe(pi->fd) == -1)
		error("Pipe");
	pi->pid = fork();
	if (pi->pid == -1)
		error("Fork");
	if (pi->pid == 0)
	{
		pi->infile = open(av[1], O_RDONLY);
		if (pi->infile == -1)
			error("infile");
		check_files(dup2(pi->infile, 0), close(pi->fd[0]), dup2(pi->fd[1], 1));
		execute(av[2], envp, -1);
	}
	else
	{
		check_files(close(pi->fd[1]), dup2(pi->fd[0], 0), close(pi->fd[0]));
		wait(NULL);
	}
}

void	next_process(char *cmd, char *env[], t_pipex *pi)
{
	if (pipe(pi->fd) == -1)
		error("Pipe");
	pi->pid = fork();
	if (pi->pid == -1)
		error("Fork");
	if (pi->pid == 0)
	{
		check_files(close(pi->fd[0]), dup2(pi->fd[1], 1), 0);
		execute(cmd, env, -1);
	}
	else
		check_files(dup2(pi->fd[0], 0), close(pi->fd[1]), close(pi->fd[0]));
}

void	last_process(int ac, char *av[], char *env[], t_pipex *pi)
{
	if (!pi->here_doc)
		pi->outfile = open(av[ac - 1], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	else if (pi->here_doc)
		pi->outfile = open(av[ac - 1], O_CREAT | O_WRONLY | O_APPEND, 0777);
	if (pi->outfile == -1)
		error("outfile");
	pi->pid = fork();
	if (pi->pid == -1)
		error("Fork");
	if (pi->pid == 0)
	{
		check_files(dup2(pi->outfile, 1), close(pi->outfile), 0);
		execute(av[ac - 2], env, -1);
	}
	else
		check_files(close(pi->outfile), 0, 0);
}
