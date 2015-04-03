/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xstrsub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmignot <tmignot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 21:21:25 by tmignot           #+#    #+#             */
/*   Updated: 2014/04/19 00:29:03 by tmignot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_xstrsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*ret;

	if (s && len)
	{
		ret = (char *)malloc(len);
		if (ret)
		{
			i = 0;
			j = 0;
			while (i < start)
				i++;
			while (j < len)
			{
				ret[j] = s[i];
				j++;
				i++;
			}
			ret[j] = 0;
		}
		return (ret);
	}
	return (NULL);
}
