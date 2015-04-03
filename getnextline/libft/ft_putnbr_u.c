/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmignot <tmignot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 08:36:37 by tmignot           #+#    #+#             */
/*   Updated: 2014/04/19 00:21:03 by tmignot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int		ft_nbrlen(unsigned int u)
{
	unsigned int	i;

	i = 0;
	while (u)
	{
		u /= 10;
		i++;
	}
	return (i);
}

int						ft_pow(unsigned int n, unsigned int p)
{
	if (p == 0)
		return (1);
	while (p > 1)
	{
		n *= n;
		p--;
	}
	return (n);
}

void					ft_putnbr_u(unsigned int n)
{
	unsigned int	len;

	if (n == 0)
		ft_putchar('0');
	else
	{
		len = ft_nbrlen(n);
		while (len)
		{
			ft_putchar(n / (ft_pow(10, (len - 1))) + '0');
			n -= (n / ft_pow(10, (len - 1))) * ft_pow(10, (len - 1));
			len--;
		}
	}
}
