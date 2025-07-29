/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenaven <abenaven@42.student.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 15:16:03 by abenaven          #+#    #+#             */
/*   Updated: 2025/07/29 18:47:35 by abenaven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


void	ft_freedom(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}


char	*lookforcmd(char **path, char **cmnd)
{
	int i;
	char *newpath;
	char *location;
	
	i = 0;
	
	while(path[i])
	{
		newpath = ft_strjoin(path[i], "/");
		if (!newpath)
			return(NULL);
		location = ft_strjoin(newpath, cmnd[0]);
		free(newpath);
		if (!location)
			return(NULL);
		if (access(location, F_OK) == 0)
			return (location);
		free (location);
		i++;
	}
	return (NULL);
}

char *findpath(char **cmnd, char **envp)
{
	int i;
	char **path;

	i = 0;
	path = NULL;
	if (ft_strchr(cmnd[0], '/'))
		if (access(cmnd[0], F_OK) == 0)
			return(ft_strdup(cmnd[0]));			
	while (envp[i])
	{
		if (strncmp("PATH=", envp[i], 5) == 0)
		{
			path = ft_split(&envp[i][5], ':');
			if (!path)
				return(NULL);
			return(lookforcmd(path, cmnd));
		}	
		i++;
	}
	if (path)
		ft_freedom(path);
	return (NULL);
}
void	pipex(t_data *data, char **envp, int *fd)
{
	pid_t child1;
	pid_t child2;
	int pip[2];
		
	
	pipe(pip);
	child1 = fork();
	if (child1 == 0)
	{
		ft_freedom(data->cmnd2);
		kid1(data ,envp, fd, pip);
	}
	child2 = fork();
	if (child2 == 0)
	{
		ft_freedom(data->cmnd1);
		kid2(data, envp, fd, pip);
	}
	close(pip[0]);
	close(pip[1]);
	wait(NULL);
	wait(NULL);
}

int     main(int argc, char **argv, char **envp)
 {
	t_data data;
	int fd[2];
	
    if (argc != 5)
		exit(1);	
	data.infile = argv[1];
	data.outfile = argv[4];
	fd[0] = open(data.infile, O_RDONLY);
	if (fd[0] < 0)
		ft_error(2);
	fd[1] = open(data.outfile, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd[1] < 0)
	{
		ft_error(2);
		close(fd[0]);
	}
	data.cmnd1 = ft_split(argv[2], ' ');
	data.cmnd2 = ft_split(argv[3], ' ');
	pipex(&data, envp, fd);
	close(fd[0]);
	close(fd[1]);
	ft_freedom(data.cmnd1);
	ft_freedom(data.cmnd2);
 }