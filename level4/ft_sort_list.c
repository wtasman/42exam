#include "list.h"

t_list	*sort_list(t_list *lst, int	(*cmp)(int, int))
{
	t_list *tmp;
	int		tmpdata;

	tmp = lst;
	while (lst->next)
	{
		if ((*cmp)(lst->data, lst->next->data) == 0)
		{
			tmpdata = lst->data;
			lst->data = lst->next->data;
			lst->next->data = tmpdata;
			lst = tmp;
		}
		lst = lst->next;
	}
	lst = tmp;
	return (lst);
}
