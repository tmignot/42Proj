/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmignot <tmignot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 11:29:57 by tmignot           #+#    #+#             */
/*   Updated: 2013/11/23 22:20:13 by tmignot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ret;
	t_list	*tmp;

	if (lst)
	{
		ret = (*f)(ft_lstnew(lst->content, lst->content_size));
		tmp = ret;
		while (lst->next)
		{
			lst = lst->next;
			tmp->next = (*f)(ft_lstnew(lst->content, lst->content_size));
			tmp = tmp->next;
		}
		return (ret);
	}
	return (NULL);
}
