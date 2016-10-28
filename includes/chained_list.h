#ifndef CHAINED_LIST_H
# define CHAINED_LIST_H

#include <stdlib.h>

typedef struct		s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;

void		list_append_front(t_list **lst, void *data);
void		list_map(t_list *lst, void (*f)(t_list, void *), void *args);
t_list		*list_new_node(void *data);

#endif
