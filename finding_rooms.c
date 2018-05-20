#include "lem_in.h"

char	*find_start_room(t_lem_in 	t)
{
	t_room *r;

	r = t.rooms;
	while (r)
	{
		if (r->start)
			return (r->name);
		r = r->next;
	}
	return (NULL);
}

int	find_start_num_room(t_lem_in 	t)
{
	t_room *r;

	r = t.rooms;
	while (r)
	{
		if (r->start)
			return (r->number);
		r = r->next;
	}
	return (-1);
}

char	*find_finish_room(t_lem_in 	t)
{
	t_room *r;

	r = t.rooms;
	while (r)
	{
		if (r->finish)
			return (r->name);
		r = r->next;
	}
	return (NULL);
}

int	find_finish_num_room(t_lem_in 	t)
{
	t_room *r;

	r = t.rooms;
	while (r)
	{
		if (r->finish)
			return (r->number);
		r = r->next;
	}
	return (-1);
}

int		find_number_room(char *s, t_room *t)
{
	int n;

	n = 0;
	while (t)
	{
		if (!ft_strcmp(t->name, s))
		{
			n = t->number;
			break;
		}
		else
			t = t->next;
	}
	return (n);
}

char	*find_name_room(int n, t_room *tmp)
{
	char *name;
    t_room *t = tmp;

	name = NULL;
	while (t)
	{
		if (t->number == n)
		{
			name = t->name;
			break;
		}
		else
			t = t->next;
	}
	return (name);
}

t_room  *find_number(t_room *tmp, int n)
{
    t_room *t = tmp;

    while (t)
    {
        if (t->number == n)
        {
            break;
        }
        else
            t = t->next;
    }
    return (t);
}

t_room  *find_name(t_room *tmp, char *n)
{
    t_room *t = tmp;

    while (t)
    {
        if (!ft_strcmp(t->name,n))
        {
            break;
        }
        else
            t = t->next;
    }
    return (t);
}