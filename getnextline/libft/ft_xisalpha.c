/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xisalpha.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmignot <tmignot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 15:36:35 by tmignot           #+#    #+#             */
/*   Updated: 2013/11/25 15:38:23 by tmignot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_xisalpha(int c)
{
	if (c)
		return ((c <= 'z' && c >= 'a') || (c <= 'Z' && c >= 'A'));
	return (0);
}
