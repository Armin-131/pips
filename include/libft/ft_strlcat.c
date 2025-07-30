/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenaven <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 19:33:44 by abenaven          #+#    #+#             */
/*   Updated: 2024/10/10 21:18:05 by abenaven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	ldst;
	size_t	lsrc;

	ldst = ft_strlen(dst);
	lsrc = ft_strlen(src);
	i = ldst;
	if (size <= ldst)
		return (size + lsrc);
	j = 0;
	while (src[j] && i < (size - 1))
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (ldst + lsrc);
}
/*
int	main(void)
{
	size_t	size = 20;
	char dst[5] = "Hello";
	const char src[] = "Word";

	printf("%ld\n", ft_strlcat(dst, src, 4));
	printf("%s", dst);
}
*/
