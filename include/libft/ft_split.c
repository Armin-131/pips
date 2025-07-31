/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenaven <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:51:48 by abenaven          #+#    #+#             */
/*   Updated: 2024/10/13 19:31:30 by abenaven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countwords(const char *s, char c)
{
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	if (!s || !c)
		return (0);
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			len++;
		i++;
	}
	return (len);
}

static int	ft_safemalloc(char **ptr, int j, size_t buff)
{
	int	i;

	i = 0;
	ptr[j] = (char *)malloc(buff);
	if (!ptr)
	{
		while (i < j)
		{
			free(ptr[i]);
			i++;
		}
		free(ptr);
		return (1);
	}
	return (0);
}

static int	ft_master(char **ptr, const char *s, char c)
{
	size_t	len;
	int		position;

	position = 0;
	while (*s)
	{
		len = 0;
		while (*s == c)
			s++;
		while (*s != '\0' && *s != c)
		{
			s++;
			len++;
		}
		if (len > 0)
		{
			if (ft_safemalloc(ptr, position, len + 1))
				return (1);
			ft_strlcpy(ptr[position], s - len, len + 1);
			position++;
		}
	}
	return (0);
}

char	**ft_split(const char *s, char c)
{
	size_t	wcount;
	char	**ptr;

	wcount = ft_countwords(s, c);
	ptr = malloc((wcount + 1) * (sizeof(char *)));
	if (!ptr)
		return (NULL);
	ptr[wcount] = NULL;
	if (ft_master(ptr, s, c))
		return (NULL);
	return (ptr);
}
/*
int	main(void)
{
	const char	s[] = "Hola";
	char		c;
	char		**ptr;

	c = ' ';
	ptr = ft_split(s, c);
	while (ptr && *ptr)
		printf("%s\n",*ptr++);
}
*/
