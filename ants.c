#include "lem_in.h"

t_ant			*fill_ants(t_lem_in t)
{
	t_ant		*ant;
	t_ant		*tmp_ant;
	int			i;

	i = 1;
	ant = (t_ant *)malloc(sizeof(t_ant));
	ant->number = i;
	ant->room = find_start_num_room(t);
	ant->next = NULL;
	tmp_ant = ant;
	i++;
	while (i <= t.sum_ants)
	{
		tmp_ant->next = (t_ant *)malloc(sizeof(t_ant));
		tmp_ant->next->number = i;
		tmp_ant->next->room = ant->room;
		tmp_ant->next->next = NULL;
		tmp_ant = tmp_ant->next;
		i++;
	}
	return (ant);
}
