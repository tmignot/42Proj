/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmignot <tmignot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 16:22:46 by tmignot           #+#    #+#             */
/*   Updated: 2015/03/24 15:18:33 by tmignot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*map;

	i = 0;
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
