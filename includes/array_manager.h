#ifndef ARRAY_MANAGER_H
# define ARRAY_MANAGER_H

#include <stdlib.h>

#include "array.h"

#define INIT_RATE 2.0
#define LEARNING_RATE 0.5

typedef enum	e_bool
{
	FALSE,
	TRUE
}				BOOL;

typedef struct	s_keys_manager
{
	t_list		*arrays;
	float		rate;
}				t_keys_manager;

void			dump(t_keys_manager *manager);
void			add_managed_key(t_keys_manager *manager, int index, int value);
int				get_managed_key(t_keys_manager *manager, int index, int *value);
t_keys_manager	*new_keys_manager(void);

#endif
