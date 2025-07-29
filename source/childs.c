/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenaven <abenaven@42.student.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:06:50 by abenaven          #+#    #+#             */
/*   Updated: 2025/07/29 18:46:17 by abenaven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	kid1(t_data *data, char **envp, int *fd, int *pip)
{
	char *location;
	
	close(pip[0]);//cerrar la lectura del wazza
	dup2(fd[0], 0); //reedirigir la lectura del stdin al infile
	close(fd[0]);//cerrar infile
	close(fd[1]);//cerrar outfile
	dup2(pip[1], 1);//redirigir escrritura de stdout al wazzaaa
	close(pip[1]); //cerrar el wazza en escritura
	location = findpath(data->cmnd1, envp);
	if (!location)
	{
		perror("hola 4");
		exit(2);
	}
	if (!execve(location,data->cmnd1, envp))
	{
		perror("hola 5");
		exit(2);
	}
	ft_freedom(data->cmnd1);
	free(location);
}

void kid2(t_data *data, char **envp, int *fd, int *pip)
{
	char *location;
	
	close(pip[1]);
	dup2(pip[0], 0);//redirigir de stdout al pipe
	close(pip[0]);
	dup2(fd[1], 1);//redirigir salida a outfile
	close(fd[0]);
	close(fd[1]);
	location = findpath(data->cmnd2, envp);
	if (!location)
		ft_error(2);
	if (!execve(location,data->cmnd2, envp))
		ft_error(2);
	ft_freedom(data->cmnd1);
}

void	error(int i)
{
	perror(ERROR1);
	exit(i);
}