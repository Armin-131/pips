/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoibutbetter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenaven <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 23:26:49 by abenaven          #+#    #+#             */
/*   Updated: 2025/03/27 23:26:50 by abenaven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	checksign(char c)
{
	if (c == '-')
		return (-1);
	return (1);
}

bool	ft_atoibutbetter(const char *nptr, int *n)
{
	int		i;
	long	fin;
	int		sign;

	i = 0;
	fin = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	sign = checksign(nptr[i]);
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i + 1] == '\0')
			return (false);
		i++;
	}
	while (nptr[i])
	{
		if (nptr[i] < '0' || nptr[i] > '9')
			return (false);
		fin = (fin * 10) + (nptr[i++] - '0');
		if ((sign * fin > INT_MAX) || (sign * fin < INT_MIN))
			return (false);
	}
	*n = sign * fin;
	return (true);
}
