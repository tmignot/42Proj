/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmignot <tmignot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 10:07:09 by tmignot           #+#    #+#             */
/*   Updated: 2014/04/19 00:21:32 by tmignot          ###   ########.fr       */
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

static int				ft_pow(unsigned int n, unsigned int p)
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

void					ft_putnbr_u_fd(unsigned int n, int fd)
{
	unsigned int	len;

	if (n == 0)
		ft_putchar_fd('0', fd);
	else
	{
		len = ft_nbrlen(n);
		while (len)
		{
			ft_putchar_fd(n / (ft_pow(10, (len - 1))) + '0', fd);
			n -= (n / ft_pow(10, (len - 1))) * ft_pow(10, (len - 1));
			len--;
		}
	}
}
