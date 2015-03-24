/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xstrjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmignot <tmignot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 20:32:11 by tmignot           #+#    #+#             */
/*   Updated: 2014/04/19 00:25:50 by tmignot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	ft_len(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char			*ft_xstrjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*ret;

	if (s1 && s2)
	{
		i = ft_len((char *)s1);
		j = ft_len((char *)s2);
		k = 0;
		ret = (char *)malloc(i + j + 1);
		if (ret)
		{
			while (++k <= i)
				ret[k - 1] = s1[k - 1];
			while (k - 1 < i + j)
			{
				ret[k - 1] = s2[k - i - 1];
				k++;
			}
			ret[k - 1] = 0;
		}
		return (ret);
	}
	return (NULL);
}
