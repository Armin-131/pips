/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenaven <abenaven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 15:16:03 by abenaven          #+#    #+#             */
/*   Updated: 2025/07/30 22:11:31 by abenaven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*lookforcmd(char **path, char **cmnd)
{
	int		i;
	char	*newpath;
	char	*location;

	i = 0;
	while (path[i])
	{
		newpath = ft_strjoin(path[i], "/");
		if (!newpath)
			return (ft_freedom(path), NULL);
		location = ft_strjoin(newpath, cmnd[0]);
		free(newpath);
		if (!location)
			return (ft_freedom(path), NULL);
		if (access(location, F_OK) == 0)
			return (ft_freedom(path), location);
		free(location);
		i++;
	}
	ft_freedom(path);
	return (NULL);
}

char	*findpath(char **cmnd, char **envp)
{
	int		i;
	char	**path;

	i = 0;
	path = NULL;
	if (ft_strchr(cmnd[0], '/'))
	{
		if (access(cmnd[0], F_OK) == 0)
			return (ft_strdup(cmnd[0]));
		ft_freedom(cmnd);
		ft_error(path, NULL, 1);
	}
	while (envp[i])
	{
		if (strncmp("PATH=", envp[i], 5) == 0)
		{
			path = ft_split(&envp[i][5], ':');
			if (!path)
				return (NULL);
			return (lookforcmd(path, cmnd));
		}
		i++;
	}
	ft_error(path, NULL, 127);
	return (NULL);
}

void	pipex(t_data *data, char **envp, int *fd)
{
	pid_t	child1;
	pid_t	child2;
	int		pip[2];

	pipe(pip);
	child1 = fork();
	if (child1 == 0)
	{
		ft_freedom(data->cmnd2);
		kid1(data, envp, fd, pip);
	}
	child2 = fork();
	if (child2 == 0)
	{
		ft_freedom(data->cmnd1);
		kid2(data, envp, fd, pip);
	}
	close(pip[0]);
	close(pip[1]);
	waitpid(child1, );
	wait(NULL);
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;
	int		fd[2];
	int status;

	if (argc != 5)
	{
		ft_putstr_fd("Wrong number of arguments. Its 5!\n", 1);
		exit(1);
	}
	data.infile = argv[1];
	data.outfile = argv[4];
	fd[0] = open(data.infile, O_RDONLY);
	if (fd[0] < 0)
	{
		ft_putstr_fd("pipex: ", 2);
		perror(data.infile);
	}
	fd[1] = open(data.outfile, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd[1] < 0)
		perror(data.outfile);
	data.cmnd1 = ft_split(argv[2], ' ');
	data.cmnd2 = ft_split(argv[3], ' ');
	status = pipex(&data, envp, fd);
	if (fd[0] >= 0)
		close(fd[0]);
	if (fd[1] >= 0)
		close(fd[1]);
	ft_freedom(data.cmnd1);
	ft_freedom(data.cmnd2);
	return (status);
}
