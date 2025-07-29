/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenaven <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 20:10:32 by abenaven          #+#    #+#             */
/*   Updated: 2024/10/10 22:02:24 by abenaven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*pb;
	char	*pl;

	pb = (char *)big;
	pl = (char *)little;
	i = 0;
	if (pl[0] == '\0')
		return (pb);
	while (i < len && pb[i])
	{
		j = 0;
		while ((i + j) < len && pb[i + j] == pl[j])
		{
			j++;
			if (pl[j] == '\0')
				return (&pb[i]);
		}
		i++;
	}
	return (NULL);
}
