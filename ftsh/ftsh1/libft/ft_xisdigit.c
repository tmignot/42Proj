/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xisdigit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmignot <tmignot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 15:40:49 by tmignot           #+#    #+#             */
/*   Updated: 2013/11/25 15:41:15 by tmignot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_xisdigit(int c)
{
	if (c)
		return ((c <= '9' && c >= '0'));
	return (0);
}
