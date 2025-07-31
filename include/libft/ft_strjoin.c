/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenaven <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 18:08:25 by abenaven          #+#    #+#             */
/*   Updated: 2024/10/10 21:35:52 by abenaven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*ptr;
	size_t	tsize;

	tsize = ft_strlen(s1) + ft_strlen(s2);
	ptr = malloc((tsize + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	ft_strlcpy (ptr, s1, tsize + 1);
	ft_strlcat (ptr, s2, tsize + 1);
	return (ptr);
}
