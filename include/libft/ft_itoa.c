/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenaven <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:11:44 by abenaven          #+#    #+#             */
/*   Updated: 2024/10/11 17:00:32 by abenaven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countdigits(int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*buff;
	int		len;
	int		tmp;

	tmp = n;
	len = ft_countdigits(n);
	if (n == 0)
		return (ft_strdup("0"));
	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	buff = ft_calloc((len + 1), sizeof(char));
	if (!buff)
		return (NULL);
	if (n < 0)
		tmp = -tmp;
	while (len-- > 0)
	{
		buff[len] = (tmp % 10) + '0';
		tmp = tmp / 10;
	}
	if (n < 0)
		buff[0] = '-';
	return (buff);
}
