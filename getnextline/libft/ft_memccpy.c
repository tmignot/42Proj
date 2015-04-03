/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmignot <tmignot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 12:22:03 by tmignot           #+#    #+#             */
/*   Updated: 2014/04/19 00:14:28 by tmignot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	size_t		i;

	i = 0;
	while (i < n)
	{
		*((char *)s1 + i) = *((char *)s2 + i);
		if (((char *)s2)[i] == (char)c)
			return (s1 + i + 1);
		i++;
	}
	return (NULL);
}
