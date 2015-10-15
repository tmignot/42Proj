/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xstrnequ.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmignot <tmignot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 20:22:57 by tmignot           #+#    #+#             */
/*   Updated: 2013/11/25 20:25:08 by tmignot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_xstrnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;

	if (s1 && s2)
	{
		i = 0;
		while (s1[i] && s2[i] && i < n)
		{
			if (s1[i] != s2[i])
				return (0);
			i++;
		}
		if (i == n)
			return (1);
		if (s1[i] || s2[i])
			return (0);
		return (1);
	}
	return (s1 || s2);
}
