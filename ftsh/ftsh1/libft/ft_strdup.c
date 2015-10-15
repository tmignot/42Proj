/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmignot <tmignot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 14:34:19 by tmignot           #+#    #+#             */
/*   Updated: 2013/11/26 03:59:26 by tmignot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	i;

	i = 0;
	while (s1[i])
		i++;
	s2 = (char *)malloc(sizeof(char) * i + 1);
	while (i)
	{
		s2[i] = s1[i];
		i--;
	}
	s2[i] = s1[i];
	return (s2);
}
