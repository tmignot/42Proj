/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmignot <tmignot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 14:04:19 by tmignot           #+#    #+#             */
/*   Updated: 2013/11/22 04:50:45 by tmignot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s2[j])
	{
		if (!s1[i] || i == n)
			return (NULL);
		if (s1[i] == s2[j])
			j++;
		else
		{
			j = 0;
			while (s1[i] == s2[j])
				j++;
		}
		i++;
	}
	return (&(((char *)s1)[i - j]));
}
