/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atodbl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenaven <abenaven@42.student.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 21:55:47 by abenaven          #+#    #+#             */
/*   Updated: 2025/05/15 17:39:29 by abenaven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atodbl(char *str)
{
	long	entero;
	double  decimales;
	double potencia;
	int		sign;

	entero = 0;
	decimales = 0;
	sign = 1;
	potencia = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32 )
		++str;
	while (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign = -sign;
	while (*str != '.' && *str)
		entero = (entero * 10) + (*str++ - '0');
	if (*str == '.')
		++str;
	while (*str)
	{
		potencia = potencia / 10;
		decimales = decimales + (*str++ - '0') * potencia;
	}
	return ((entero + decimales) * sign);
}