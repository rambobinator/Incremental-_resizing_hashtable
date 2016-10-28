#include "chained_list.h"

void		list_append(t_list *lst, void *data)
{
	t_list	*it;

	it = lst;
	while (it->next)
		it = it->next;
	it->next = list_new_node(data);
}

void		list_map(t_list *lst, void (*f)(t_list, void *), void *args)
{
	t_list	*it;

	it = lst;
	while (it)
	{
		f(*it, args);
		it = it->next;
	}
}

t_list		*list_new_node(void *data)
{
	t_list	*new_node;

	if (!(new_node = (t_list *)malloc(sizeof(t_list))))
		return NULL;
	new_node->data = data;
	new_node->next = NULL;
	return (new_node);
}
