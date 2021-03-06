/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xstrclr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmignot <tmignot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 21:18:42 by tmignot           #+#    #+#             */
/*   Updated: 2013/11/25 21:18:49 by tmignot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	ft_xstrclr(char *s)
{
	size_t	i;

	if (s)
	{
		i = 0;
		while (s[i])
			s[i++] = 0;
	}
}
