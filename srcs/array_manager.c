#include "array_manager.h"

#include <stdio.h>

void			add_managed_key(t_keys_manager *manager, int index, int value)
{
	ARRAY_ERROR	err;
	t_array		*tab;
	int			new_size;

	new_size = manager->rate * ((t_array *)manager->arrays->data)->size;
	tab = manager->arrays->data;
	if ((err = add_value(tab, index, value)) == OK)
		return ;
	if (err == CRITIC)
		return ; /* SHOULD BEGIN COPYING */
	if ((err == OUT_OF_RANGE) && (index > new_size))
		new_size = index + 1;
	manager->rate += LEARNING_RATE;
	list_append_front(&manager->arrays, new_array(new_size));
	add_managed_key(manager, index, value);
}

static void		clean(t_list *lst, t_list *node)
{
	(void)lst;
	(void)node;
	/* THINK ABOUT A NICE WAY TO FREE NODE CONTENT */
}

int				get_managed_key(t_keys_manager *manager, int index, int *value)
{
	t_array		*tab;
	t_list		*it;
	BOOL		depth;

	*value = EMPTY;
	it = manager->arrays;
	depth = FALSE;
	while (it)
	{
		tab = it->data;
		if (depth && (get_value(tab, index, value) == OK))
		{
			add_managed_key(manager, index, *value);
			clear_index(tab, index);
			if (tab->filling_size == 0)
				clean(manager->arrays, it);
		}
		else
			get_value(tab, index, value);
		it = it->next;
		depth = TRUE;
	}
	return (*value);
}

t_keys_manager	*new_keys_manager(void)
{
	t_keys_manager	*new_manager;

	if (!(new_manager = (t_keys_manager *)malloc(sizeof(t_keys_manager))))
		return NULL;
	new_manager->rate = INIT_RATE;
	new_manager->arrays = list_new_node(new_array(ARRAY_INIT_SIZE));
	return (new_manager);
}

static void		write_tab_dump(t_list node, void *arg)
{
	(void)arg;
	t_array		*tab;
	int			i;

	i = -1;
	tab = (t_array *)node.data;
	printf("ARRAY SIZE: %d\n", tab->size);
	while (++i < tab->size)
		printf("%d /", tab->data[i]);
	printf("\n\n");
}

void			dump(t_keys_manager *manager)
{
	list_map(manager->arrays, write_tab_dump, NULL);
}
