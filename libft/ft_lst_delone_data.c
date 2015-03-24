/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_delone_data.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmignot <tmignot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/19 00:07:30 by tmignot           #+#    #+#             */
/*   Updated: 2014/04/19 00:08:44 by tmignot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		lst_delone_data(t_lst **head, t_lst *lst)
{
	if (lst->prev)
		lst->prev->next = lst->next;
	else
		*head = lst->next;
	if (lst->next)
		lst->next->prev = lst->prev;
	free(lst->data);
	free(lst);
}
