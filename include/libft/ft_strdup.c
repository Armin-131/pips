/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenaven <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 19:47:42 by abenaven          #+#    #+#             */
/*   Updated: 2024/10/10 21:56:31 by abenaven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	ls;
	char	*ptr;

	ls = ft_strlen(s);
	ptr = malloc(ls + 1);
	if (!ptr)
		return (0);
	ft_strlcpy(ptr, s, ls + 1);
	return (ptr);
}
