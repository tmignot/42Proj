/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xstrtrim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmignot <tmignot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 21:24:07 by tmignot           #+#    #+#             */
/*   Updated: 2013/11/25 21:24:19 by tmignot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_xstrtrim(char const *s)
{
	char	*ret;
	size_t	end;
	size_t	start;
	size_t	i;

	if (s == NULL)
		return (NULL);
	end = 0;
	start = 0;
	while (s[end])
		end++;
	while (!s[end] || s[end] == ' ' || s[end] == '\n' || s[end] == '\t')
		end--;
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		start++;
	ret = (char *)malloc(end - start);
	if (ret)
	{
		i = 0;
		while (start <= end)
			ret[i++] = s[start++];
		ret[i] = 0;
	}
	return (ret);
}
