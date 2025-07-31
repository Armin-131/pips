/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenaven <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 19:48:23 by abenaven          #+#    #+#             */
/*   Updated: 2025/03/01 19:48:26 by abenaven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	overhandle(long fin, int sign, char s)
{
	if (fin > LONG_MAX / 10 || (fin == LONG_MAX / 10 && s > '7'))
	{
		if (sign == 1)
			return (LONG_MAX);
		else
			return (LONG_MIN);
	}
	return (0);
}

long	ft_atol(char *s)
{
	int		i;
	long	fin;
	long	checkover;
	int		sign;

	i = 0;
	fin = 0;
	sign = 1;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == ' ')
		i++;
	if ((s[i] == '-') || (s[i] == '+'))
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		checkover = overhandle(fin, sign, s[i]);
		if (checkover)
			return (checkover);
		fin = (fin * 10) + (s[i++] - '0');
	}
	return (sign * fin);
}
