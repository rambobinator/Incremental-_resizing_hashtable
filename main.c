#include <stdio.h>
#include "includes/array_manager.h"

int main(void)
{
	t_keys_manager	*manager;
	int				i;
	int				val;

	i = -1;
	manager = new_keys_manager();
	while (++i < 30)
		add_managed_key(manager, i, i);
	dump(manager);
	while (--i >= 0)
	{
		get_managed_key(manager, i, &val);
		printf("%d\n", val);
	}
	dump(manager);
	return (0);
}
