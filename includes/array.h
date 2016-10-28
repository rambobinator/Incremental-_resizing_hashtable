#ifndef ARRAY_H
# define ARRAY_H

#include <stdlib.h>

#include "chained_list.h"

#define EMPTY -1
#define ARRAY_INIT_SIZE 10
#define CRITIC_FILLING_PERCENT 70

#define GET_FILLING_PERCENT(fill, size) (fill * 100) / size

typedef	enum	e_array_error
{
	OUT_OF_RANGE,
	EXIST,
	NOT_FOUND,
	FULL,
	CRITIC,
	OK
}				ARRAY_ERROR;

typedef struct	s_array
{
	int			size;
	int			filling_size;
	int			*data;
}				t_array;

ARRAY_ERROR		add_value(t_array *tab, int index, int val);
ARRAY_ERROR		clear_index(t_array *tab, int index);
ARRAY_ERROR		get_value(t_array *tab, int index, int *val);

void			del_array(t_array *array);
t_array			*new_array(const int size);

#endif
