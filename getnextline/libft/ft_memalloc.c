/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmignot <tmignot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 16:01:47 by tmignot           #+#    #+#             */
/*   Updated: 2014/04/19 00:14:02 by tmignot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*m;
	size_t	i;

	m = malloc(size);
	if (m)
	{
		i = 0;
		while (i < size)
			((char *)m)[i++] = 0;
		return (m);
	}
	return (NULL);
}
