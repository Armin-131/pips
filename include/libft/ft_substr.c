/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenaven <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 21:34:44 by abenaven          #+#    #+#             */
/*   Updated: 2024/10/10 20:41:16 by abenaven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	ls;
	size_t	i;
	char	*psub;

	ls = ft_strlen(s);
	i = 0;
	if (start >= ls)
		return (ft_calloc(1, 1));
	if (len + start > ls)
		len = ls - start;
	psub = malloc((len + 1) * sizeof(char));
	if (!psub)
		return (NULL);
	while (i < len && s[i])
	{
		psub[i] = s[start];
		i++;
		start++;
	}
	psub[i] = '\0';
	return (psub);
}
