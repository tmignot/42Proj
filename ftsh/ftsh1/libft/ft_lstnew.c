/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmignot <tmignot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 03:34:13 by tmignot           #+#    #+#             */
/*   Updated: 2014/04/19 00:13:24 by tmignot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content, size_t content_size)
{
	t_list	*elem;

	elem = (t_list *)malloc(sizeof(t_list));
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
		elem->next = NULL;
	}
	return (elem);
}
