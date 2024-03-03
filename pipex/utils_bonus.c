/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudar <hboudar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:46:52 by hboudar           #+#    #+#             */
/*   Updated: 2024/02/28 00:16:30 by hboudar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	error(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

static void	ft_free(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

char	*find_path(char *cmd, char *env[], int i, int found)
{
	char		*path;
	char		**str;

	while (!ft_strnstr(env[i], "PATH", 4))
		i++;
	(1) && (str = ft_split(env[i] + 5, ':'), i = -1);
	if (!str)
		error("Malloc");
	while (str[++i])
	{
		path = ft_strjoin(ft_strjoin(str[i], "/"), cmd);
		(!path) && (ft_free(str), i = 0);
		(!access(path, X_OK)) && (found = i);
		if (found != -1)
			break ;
		free(path);
	}
	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
	if (found == -1)
		return (NULL);
	return (path);
}

void	execute(char *arg_cmd, char *env[], int i)
{
	char	**cmd;
	char	*path;
	int		mode;

	cmd = ft_split(arg_cmd, ' ');
	if (!cmd)
		error("Malloc");
	mode = (ft_strchr(cmd[0], '/') == NULL);
	if (mode)
	{
		path = find_path(cmd[0], env, 0, -1);
		while (!path && cmd[++i])
			free(cmd[i]);
		if (!path)
		{
			free(cmd);
			error("Malloc");
		}
	}
	else if (!mode)
		path = cmd[0];
	if (execve(path, cmd, env) == -1)
		error("Execve");
}

void	check_files(int a, int b, int c)
{
	if (a == -1 || b == -1 || c == -1)
		error("File");
}
