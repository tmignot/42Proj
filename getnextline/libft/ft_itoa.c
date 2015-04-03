/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmignot <tmignot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 23:06:37 by tmignot           #+#    #+#             */
/*   Updated: 2014/04/19 00:12:39 by tmignot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_numlen(int n)
{
	size_t	i;

	i = 0;
	if (!n)
		return (1);
	while (n)
	{
		i++;
		n /= 10;
	}
	return (i);
}

static size_t		ft_get_sign(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

static size_t		ft_abs(int n)
{
	if (n < 0)
		return (-1 * n);
	return (n);
}

char				*ft_itoa(int n)
{
	char	*ret;
	size_t	i;
	size_t	sign;

	sign = ft_get_sign(n);
	n = (sign) ? -n : n;
	i = ft_numlen(n);
	ret = (char *)malloc(i + sign + 1);
	if (ret)
	{
		ret[i + sign] = 0;
		if (!n)
			ret[0] = 48;
		while (n)
		{
			ret[--i + sign] = ft_abs(n % 10) + 48;
			n /= 10;
		}
		if (sign)
			ret[0] = '-';
	}
	return (ret);
}
