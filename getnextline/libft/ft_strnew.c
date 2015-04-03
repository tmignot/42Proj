/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmignot <tmignot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 16:08:33 by tmignot           #+#    #+#             */
/*   Updated: 2013/11/25 10:41:31 by tmignot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	void	*m;
	size_t	i;

	m = (char *)malloc(size + 1);
	if (m)
	{
		i = 0;
		while (i < size + 1)
			((char *)m)[i++] = 0;
		return (m);
	}
	return (NULL);
}
