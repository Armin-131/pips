/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenaven <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 19:59:46 by abenaven          #+#    #+#             */
/*   Updated: 2024/10/10 21:54:24 by abenaven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*temp;

	temp = (char *)s;
	while (n--)
		*temp++ = c;
	return (s);
}
/*
int	main(void)
{
	char	s[50] = "lalalalaalalall";
	int	c;
	size_t	n;

	c = 'p';
	n = 5;
	printf("%s", ft_memset(s, c, n));
}
*/	
