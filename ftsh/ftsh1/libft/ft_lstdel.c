/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmignot <tmignot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 04:26:22 by tmignot           #+#    #+#             */
/*   Updated: 2013/11/23 11:34:26 by tmignot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *))
{
	t_list	*elem;
	t_list	*tmp;

	elem = *alst;
	while (elem)
	{
		tmp = elem->next;
		(*del)(elem->content);
		free(elem);
		elem = tmp;
	}
	*alst = NULL;
}
