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
	int			*new_tab;
	int			i;

	i = -1;
	if (!(new_array = (t_array *)malloc(sizeof(t_array))))
		return NULL;
	if (!(new_tab = (int *)malloc(sizeof(int) * size)))
		return NULL;
	new_array->size = size;
	new_array->filling_size = 0;
	new_array->data = new_tab;
	while (++i < new_array->size)
		new_array->data[i] = EMPTY;
	return (new_array);
}
