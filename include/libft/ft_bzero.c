/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenaven <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:10:22 by abenaven          #+#    #+#             */
/*   Updated: 2024/10/10 20:35:40 by abenaven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_bzero(void *s, size_t n)
{
	char	*temp;

	temp = (char *)s;
	while (n--)
		*temp++ = '\0';
}
/*
int	main(void)
{
	char	s[10] = "abcdefghi";
	size_t	n;

	n = 5;
	ft_bzero(s, n);
	printf("%s", s);
}
*/
