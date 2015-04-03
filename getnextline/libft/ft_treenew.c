/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treenew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmignot <tmignot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 04:41:37 by tmignot           #+#    #+#             */
/*   Updated: 2013/11/25 04:42:55 by tmignot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_tree	*ft_treenew(void const *content, size_t content_size)
{
	t_tree	*elem;

	elem = (t_tree *)malloc(sizeof(t_tree));
	if (elem)
	{
		if (content)
		{
			elem->content = malloc(content_size);
			ft_memcpy(elem->content, content, content_size);
			elem->content_size = content_size;
		}
		else
		{
			elem->content = NULL;
			elem->content_size = 0;
		}
		elem->left = NULL;
		elem->right = NULL;
	}
	return (elem);
}
