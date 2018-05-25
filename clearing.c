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

void	free_connect(t_connect *c)
{
	t_connect *tmp = c;
	while (c)
	{
		tmp = c;
		c = c->next;
		free(tmp->r);
		free(tmp);
	}
}

void	free_lst(t_list *c)
{
	t_list *tmp = c;
	while (c)
	{
		tmp = c;
		c = c->next;
		free_connect(tmp->content);
		free(tmp);
	}	
}

void	free_arr_connect(t_connect_arr *c)
{
	t_connect_arr *tmp = c;
	while (c)
	{
		tmp = c;
		c = c->next;
		free_connect(tmp->s);
		free(tmp);
	}
}

void	free_ants(t_ant *c)
{
	t_ant *tmp = c;
	while (c)
	{
		tmp = c;
		c = c->next;
		free(tmp);
	}
}
