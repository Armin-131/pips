/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenaven <abenaven@42.student.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 14:02:12 by abenaven          #+#    #+#             */
/*   Updated: 2025/07/29 18:46:44 by abenaven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "libft.h"
# include <sys/wait.h>
# include <fcntl.h>
# include <stdbool.h>

# define ERROR1 "Error: "

typedef struct s_data
{
	char **cmnd1;
	char **cmnd2;
	char *infile;
	char *outfile;
	
}	t_data;


char *findpath(char **cmnd, char **envp);
void	pipex(t_data *data, char **envp, int *fd);
char	*lookforcmd(char **path, char **cmnd);
void	ft_freedom(char **matrix);
void	kid1(t_data *data, char **envp, int *fd, int *pip);
void kid2(t_data *data, char **envp, int *fd, int *pip);
void	ft_error(int i);
#endif