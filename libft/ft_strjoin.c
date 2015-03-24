/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmignot <tmignot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:28:42 by tmignot           #+#    #+#             */
/*   Updated: 2014/04/19 00:22:51 by tmignot          ###   ########.fr       */
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

char			*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*ret;

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
