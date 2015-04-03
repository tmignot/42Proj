/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xstrsplit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmignot <tmignot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 21:20:26 by tmignot           #+#    #+#             */
/*   Updated: 2014/04/19 00:27:59 by tmignot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_tablen(const char *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			j++;
		while (s[i] && s[i] != c)
			i++;
		while (s[i] && s[i] == c)
			i++;
	}
	return (j);
}

static size_t		ft_wi(size_t index, const char *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			j++;
		if (j == index + 1)
			return (i);
		while (s[i] && s[i] != c)
			i++;
	}
	return (0);
}

static size_t		ft_wl(size_t index, const char *s, char c)
{
	size_t	i;
	size_t	ret;

	i = ft_wi(index, s, c);
	ret = 0;
	while (s[i] && s[i] != c)
	{
		i++;
		ret++;
	}
	return (ret);
}

char				**ft_xstrsplit(char const *s, char c)
{
	char	**ret;
	size_t	i;
	size_t	j;
	size_t	l;

	if (!s || !c)
		return (NULL);
	ret = (char **)malloc(sizeof(char *) * ft_tablen(s, c) + 1);
	if (ret)
	{
		j = -1;
		while (++j, j < ft_tablen(s, c))
		{
			ret[j] = (char *)malloc(ft_wl(j, s, c));
			if (ret[j] && !(l = 0))
			{
				i = ft_wi(j, s, c);
				while (i - ft_wi(j, s, c) < ft_wl(j, s, c))
					ret[j][l++] = s[i++];
				ret[j][l] = 0;
			}
		}
		ret[j] = NULL;
	}
	return (ret);
}
