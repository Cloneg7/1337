/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudar <hboudar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 20:01:52 by hboudar           #+#    #+#             */
/*   Updated: 2024/02/27 23:53:09 by hboudar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "libft/libft.h"

void	error(char *msg);
void	check_files(int a, int b, int c);
void	execute(char *arg_cmd, char *env[], int i);

void	first_process(char *av[], char *envp[], int fd[2]);
void	last_process(int ac, char *av[], char *env[]);

#endif