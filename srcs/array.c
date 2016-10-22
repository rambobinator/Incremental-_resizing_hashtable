#include "array.h"

ARRAY_ERROR		add_value(t_array *tab, int index, int val)
{
	char		filling_percent;

	if ((index < 0) || (index >= tab->size))
		return (OUT_OF_RANGE);
	filling_percent = GET_FILLING_PERCENT(tab->filling_size, tab->size);
	if (filling_percent > 99)
		return (FULL);
	if (tab->data[index] != EMPTY)
		return (EXIST);
	tab->data[index] = val;
	tab->filling_size++;
	return (filling_percent > CRITIC_FILLING_PERCENT) ? CRITIC : OK;
}

t_array			*new_array(const int size)
{
	t_array		*new_array;
	int			object_size;
	int			i;

	i = -1;
	object_size = sizeof(t_array) + (size * PTR_SIZE);
	if (!(new_array = (t_array *)malloc(object_size)))
		return NULL;
	new_array->size = size;
	new_array->filling_size = 0;
	new_array->data = (int *)(new_array + sizeof(t_array));
	while (++i < new_array->size)
		new_array->data[i] = EMPTY;
	return (new_array);
}
