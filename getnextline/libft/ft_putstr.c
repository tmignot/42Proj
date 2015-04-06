/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmignot <tmignot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 23:35:26 by tmignot           #+#    #+#             */
/*   Updated: 2013/11/25 15:48:10 by tmignot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char const *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	write(1, s, i);
}