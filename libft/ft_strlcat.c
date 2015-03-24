/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmignot <tmignot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 15:26:11 by tmignot           #+#    #+#             */
/*   Updated: 2014/04/19 00:23:17 by tmignot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	l;

	i = 0;
	j = 0;
	k = 0;
	l = 0;
	while (src[k])
		k++;
	while (dst[j])
	{
		j++;
		l++;
	}
	while (src[i] && j + 1 < size)
		dst[j++] = src[i++];
	dst[j] = 0;
	if (size < l)
		return (size + k);
	return (k + l);
}
