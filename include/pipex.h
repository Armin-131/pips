/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenaven <abenaven@42.student.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 14:02:12 by abenaven          #+#    #+#             */
/*   Updated: 2025/07/31 14:46:00 by abenaven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "libft.h"
# include <fcntl.h>
# include <stdbool.h>
# include <sys/wait.h>

typedef struct s_data
{
	char	**cmnd1;
	char	**cmnd2;
	char	*infile;
	char	*outfile;

}			t_data;

char		*findpath(char **cmnd, char **envp);
int		pipex(t_data *data, char **envp, int *fd);
char		*lookforcmd(char **path, char **cmnd);
void		kid1(t_data *data, char **envp, int *fd, int *pip);
int		kid2(t_data *data, char **envp, int *fd, int *pip);
int		ft_error(char **matrix, char *s, int i);
void	fderror(char *s);
int  nocommand(char **matrix, int i);
void	wrongnumber(int i);

#endif