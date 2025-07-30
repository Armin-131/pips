/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenaven <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:09:31 by abenaven          #+#    #+#             */
/*   Updated: 2024/10/11 19:56:48 by abenaven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*lo;
	size_t		i;

	lo = 0;
	i = 0;
	if ((char)c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i])
	{
		if (s[i] == (char)c)
			lo = &(s[i]);
		i++;
	}
	return ((char *)lo);
}
/*
int	main(void)
{
	const char	s[] = "Hello World";
	int			c;

	c = (char *)'o';
	printf("%p", ft_strrchr(s, c));
	return (0);
}
*/
