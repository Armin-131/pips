/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenaven <abenaven@42.student.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 01:33:12 by abenaven          #+#    #+#             */
/*   Updated: 2025/07/31 14:47:19 by abenaven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_error(char **matrix, char *s, int i)
{
	if (matrix)
	{
		perror(matrix[0]);
		ft_freedom(matrix);
	}
	if (s)
	{
		perror(s);
		free(s);
	}
	exit(i);
}

void	fderror(char *s)
{
	ft_putstr_fd("pipex: ", 2);
	perror(s);
}

int nocommand(char **matrix, int i)
{
	if (matrix[0] == NULL)
	{
		ft_freedom(matrix);
		exit(i);
	}
	ft_putstr_fd(matrix[0], 2);
	ft_putstr_fd(": command not found\n", 2);
	ft_freedom(matrix);
	exit (i);
}
void	wrongnumber(int i)
{
	ft_putstr_fd("Wrong number of arguments. file1 cmnd1 cmnd2 file2\n", i);
	exit(i);
}
