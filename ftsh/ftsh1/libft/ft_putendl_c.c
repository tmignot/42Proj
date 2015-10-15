/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmignot <tmignot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/18 23:53:54 by tmignot           #+#    #+#             */
/*   Updated: 2014/04/19 00:19:51 by tmignot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_c(char *c, char *str)
{
	ft_putstr(c);
	ft_putstr(str);
	ft_putstr(RES);
	ft_putchar('\n');
}
