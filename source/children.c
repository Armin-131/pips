/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenaven <abenaven@42.student.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:06:50 by abenaven          #+#    #+#             */
/*   Updated: 2025/07/30 13:39:56 by abenaven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	kid1(t_data *data, char **envp, int *fd, int *pip)
{
	char *location;
	
	close(pip[0]);//cerrar la lectura del wazza
	dup2(fd[0], 0);
	if (fd[0] >= 0) //redirigir la lectura del stdin al infile
		close(fd[0]);//cerrar infile
	if(fd[1] >= 0)
		close(fd[1]);//cerrar outfile
	dup2(pip[1], 1);//redirigir escrritura del stdout al wazzaaa
	close(pip[1]); //cerrar el wazza en escritura
	if (fd[0] < 0)
	{
		ft_freedom(data->cmnd1);
		exit(2);
	}
	location = findpath(data->cmnd1, envp);
	if (!location)
		ft_error(data->cmnd1, location, 2);
	if (!execve(location, data->cmnd1, envp))
		ft_error(data->cmnd1, location, 2);
	free(location);
}

void kid2(t_data *data, char **envp, int *fd, int *pip)
{
	char *location;
	
	close(pip[1]);
	dup2(pip[0], 0);//redirigir de stdout al pipe
	close(pip[0]);
	dup2(fd[1], 1);
	if (fd[0] >= 0)//redirigir salida a outfile
		close(fd[0]);
	if (fd[1] >= 0)
		close(fd[1]);
	if (fd[1] < 0)
	{
		ft_freedom(data->cmnd2);
		exit(2);
	}
	location = findpath(data->cmnd2, envp);
	if (!location)
		ft_error(data->cmnd2, NULL, 2);
	if (!execve(location, data->cmnd2, envp))
		ft_error(data->cmnd2, location, 2);
	free(location);
}

void	ft_error(char **matrix,char *s, int i)
{
	if (matrix)
		ft_freedom(matrix);
	if (s)
		free(s);
	perror(ERROR1);
	exit(i);
}
