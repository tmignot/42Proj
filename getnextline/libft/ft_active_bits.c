/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_active_bits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmignot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/20 11:14:01 by tmignot           #+#    #+#             */
/*   Updated: 2014/04/19 00:11:25 by tmignot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_active_bits(int value)
{
	unsigned int	i;

	i = 0;
	while (value > 0)
	{
		if (value % 2)
			i++;
		value = value >> 1;
	}
	return (i);
}
