/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xstrmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmignot <tmignot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 20:35:19 by tmignot           #+#    #+#             */
/*   Updated: 2015/03/24 15:18:19 by tmignot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_xstrmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*map;

	i = 0;
	if (s && f)
	{
		while (s[i])
			i++;
		map = (char *)malloc(i + 1);
		if (map)
		{
			while (i--)
				map[i] = (*f)(s[i]);
		}
		return (map);
	}
	return (NULL);
}
