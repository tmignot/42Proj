/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmignot <tmignot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/03 06:24:31 by tmignot           #+#    #+#             */
/*   Updated: 2014/04/18 23:45:34 by tmignot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		lst_push(t_lst **head, int type, void *data)
{
	t_lst	*tmp;
	t_lst	*lst;

	lst = ft_memalloc(sizeof(t_lst));
	lst->type = type;
	lst->data = data;
	lst->next = NULL;
	lst->prev = NULL;
	tmp = *head;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = lst;
		lst->prev = tmp;
	}
	else
		*head = lst;
}
