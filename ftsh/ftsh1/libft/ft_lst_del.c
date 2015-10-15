#include "libft.h"

void		lst_del(t_lst **head)
{
	t_lst		**h;
	t_lst		*tmp_next;

	while(*head)
	{
		tmp_next = (*head)->next;
		lst_delone_data(head, *head);
		*head = tmp_next;
	}
}
