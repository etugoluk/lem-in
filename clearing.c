#include "lem_in.h"

void	free_arr(char **arr)
{
	int			i;

	i = 0;
	while (arr[i])
	{
		ft_strdel(&arr[i]);
		i++;
	}
	free(arr);
}

void	free_rooms(t_room *r)
{
	t_room *tmp = r;
	while (r)
	{
		tmp = r;
		r = r->next;
		free(tmp->name);
		free(tmp);
	}
}

void free_struct(t_lem_in *t)
{
	free_arr(t->con);
	free_rooms(t->rooms);
}
