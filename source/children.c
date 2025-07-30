/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenaven <abenaven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:06:50 by abenaven          #+#    #+#             */
/*   Updated: 2025/07/30 21:15:50 by abenaven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	kid1(t_data *data, char **envp, int *fd, int *pip)
{
	char	*location;

	close(pip[0]);
	dup2(fd[0], 0);
	if (fd[0] >= 0)
		close(fd[0]);
	if (fd[1] >= 0)
		close(fd[1]);
	dup2(pip[1], 1);
	close(pip[1]);
	if (fd[0] < 0)
	{
		ft_freedom(data->cmnd1);
		exit(1);
	}
	location = findpath(data->cmnd1, envp);
	if (!location)
		ft_error(data->cmnd1, location, 1);
	if (!execve(location, data->cmnd1, envp))
		ft_error(data->cmnd1, location, 127);
	free(location);
}

void	kid2(t_data *data, char **envp, int *fd, int *pip)
{
	char	*location;

	close(pip[1]);
	dup2(pip[0], 0);
	close(pip[0]);
	dup2(fd[1], 1);
	if (fd[0] >= 0)
		close(fd[0]);
	if (fd[1] >= 0)
		close(fd[1]);
	if (fd[1] < 0)
	{
		ft_freedom(data->cmnd2);
		exit(1);
	}
	location = findpath(data->cmnd2, envp);
	if (!location)
		ft_error(data->cmnd2, NULL, 1);
	if (!execve(location, data->cmnd2, envp))
		ft_error(data->cmnd2, location, 127);
	free(location);
}

void	ft_error(char **matrix, char *s, int i)
{
	if (matrix)
		ft_freedom(matrix);
	if (s)
		free(s);
	perror(ERROR1);
	exit(i);
}
