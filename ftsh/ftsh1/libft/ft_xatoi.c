/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xatoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmignot <tmignot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 15:32:11 by tmignot           #+#    #+#             */
/*   Updated: 2014/04/19 00:28:41 by tmignot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

static int		ft_iswhitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\f'
	|| c == '\v');
}

int				ft_xatoi(const char *str)
{
	size_t	i;
	int		res;
	int		sign;

	if (str)
	{
		i = 0;
		res = 0;
		sign = 1;
		while (ft_iswhitespace(str[i]))
			i++;
		if (str[i] == '-' || str[i] == '+')
			sign = (str[i++] == '-') ? -1 : 1;
		while (str[i] && str[i] >= '0' && str[i] <= '9')
		{
			res *= 10;
			res += (str[i] - 48);
			i++;
		}
		return (res * sign);
	}
	return (0);
}
