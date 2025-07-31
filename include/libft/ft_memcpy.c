/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenaven <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 19:20:12 by abenaven          #+#    #+#             */
/*   Updated: 2024/10/10 21:51:08 by abenaven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*tsrc;
	unsigned char	*tdest;
	size_t			i;

	tsrc = (unsigned char *)src;
	tdest = (unsigned char *)dest;
	i = 0;
	if (!src && !dest)
		return (0);
	while (i < n)
	{
		tdest[i] = tsrc[i];
		i++;
	}
	return (dest);
}
/*
int	main(void)
{
	char	dest[50] = "Hello";
	char	*src = "World";
	size_t	n = 5;

	printf("%s\n" ,dest);
	ft_memcpy(dest, src, 5);
	printf("%s", dest);
	
	return (0);
}
*/
