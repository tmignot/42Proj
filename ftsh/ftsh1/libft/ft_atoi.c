/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmignot <tmignot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 14:22:00 by tmignot           #+#    #+#             */
/*   Updated: 2014/04/19 00:17:47 by tmignot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

static int		ft_iswhitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\f'
	|| c == '\v');
}

int				ft_atoi(const char *str)
{
	size_t	i;
	long	res;
	long	old;
	int		sign;

	i = 0;
	res = 0;
	old = 0;
	sign = 1;
	while (ft_iswhitespace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		sign = (str[i++] == '-') ? -1 : 1;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		old = res;
		res *= 10;
		res += (str[i] - 48);
		i++;
		if (old > res)
			return (-1);
	}
	return (res * sign);
}
