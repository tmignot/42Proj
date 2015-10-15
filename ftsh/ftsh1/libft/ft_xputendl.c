/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xputendl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmignot <tmignot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 15:46:30 by tmignot           #+#    #+#             */
/*   Updated: 2013/11/25 15:46:33 by tmignot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_xputendl(char const *s)
{
	size_t	i;

	if (s)
	{
		i = 0;
		while (s[i])
			i++;
		write(1, s, i);
		write(1, "\n", 1);
	}
}
