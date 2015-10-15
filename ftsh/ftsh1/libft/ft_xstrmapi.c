/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xstrmapi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmignot <tmignot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 21:11:54 by tmignot           #+#    #+#             */
/*   Updated: 2015/03/24 15:18:02 by tmignot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_xstrmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*map;

	if (s && f)
	{
		i = 0;
		while (s[i])
			i++;
		map = (char *)malloc(i + 1);
		if (map)
		{
			while (i--)
				map[i] = (*f)(i, s[i]);
		}
		return (map);
	}
	return (NULL);
}
