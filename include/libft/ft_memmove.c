/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenaven <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 17:20:21 by abenaven          #+#    #+#             */
/*   Updated: 2024/10/10 21:52:06 by abenaven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*tdest;
	unsigned char	*tsrc;
	size_t			i;

	tsrc = (unsigned char *) src;
	tdest = (unsigned char *) dest;
	i = 0;
	if (!dest && !src)
		return (0);
	if (tdest > tsrc)
	{
		while (n--)
			tdest[n] = tsrc[n];
	}
	else if (tdest < tsrc)
	{
		while (i < n)
		{
			*tdest = *tsrc;
			tdest++;
			tsrc++;
			i++;
		}
	}
	return (dest);
}
/*
int	main(void)
{
	char	dest[50] = "colita";
	char	*src = dest + 3;
	src[0] = 'p';
	src[1] = 'o';
	src[2] = 'l';
	size_t	n = 5;

	printf("%s",(char *)ft_memmove(dest, src, 5));

	return (0);
}
*/
