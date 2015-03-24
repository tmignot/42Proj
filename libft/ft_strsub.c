/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmignot <tmignot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:13:05 by tmignot           #+#    #+#             */
/*   Updated: 2014/04/19 00:24:46 by tmignot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*ret;

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
