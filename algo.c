#include "lem_in.h"

t_connect			*new_connect(char *s)
{
	t_connect		*t;

	if (!(t = (t_connect *)malloc(sizeof(t_connect))))
		return (NULL);
	if (!(t->r = ft_strdup(s)))
	{
		free(t);
		return (NULL);
	}
	t->next = NULL;
	return (t);
}

int cmp_connects(t_connect *t1, t_connect *t2, int f, t_lem_in l)
{
	if (!t1 || !t2 || !(t1->r) || !(t2->r))
		return (1);
	while (t1 && t2 && t1->r != find_name_room(f, l.rooms) && t2->r != find_name_room(f, l.rooms))
	{
		if (!ft_strcmp(t1->r,t2->r))
		{
			t1 = t1->next;
			t2 = t2->next;
		}
		else
			return (1);
	}
	if ((!t1 && !t2) || (t2 && !ft_strcmp(t2->r, find_name_room(f, l.rooms))))
		return (0);
	return (1);
}

int cmp_arr_con(t_connect *t, t_lem_in l)
{
	int f;

	f = find_finish_num_room(l);
	if (!(l.arr))
		return (1);
	while (l.arr)
	{
		if (!cmp_connects(t, (l.arr)->s, f, l))
			return (0);
		else
			l.arr = (l.arr)->next;
	}
	return (1);
}

int			has_cycle(char *s, t_connect *t)
{
	while (t)
	{
		if (!ft_strcmp(s, t->r))
			return (1);
		t = t->next;
	}
	return (0);
}

void		clear_con(char *s, t_connect *t)
{
	t_connect *tmp;
	t_connect *tmp1;

	if (!s || !t)
		return ;
	tmp = t;
	while (tmp && tmp->next)
	{
		if (!ft_strcmp(s, tmp->next->r))
		{
			tmp1 = tmp->next;
			tmp->next = tmp->next->next;
			free(tmp1->r);
			free(tmp1);
		}
		tmp = tmp->next;
	}
}

t_connect		*finding(t_lem_in l, t_connect *head, t_connect *t, int i)
{
	int j = 0;

	while (l.con[i][j])
	{
		if (l.con[i][j] == '1')
		{
			if (has_cycle(find_name_room(j, l.rooms), head))
				j++;
			else if (j == find_finish_num_room(l) && cmp_arr_con(head, l))
			{
				t->next = new_connect(find_name_room(j, l.rooms));
				return (head);
			}
			else if (j == find_finish_num_room(l) && (!cmp_arr_con(head, l)))
			{
				clear_con(find_name_room(i, l.rooms), head);
				return (NULL);
			}
			else if (find_path(j, l))
				return (head);
			else
				j++;
		}
		else
			j++;
	}
	clear_con(find_name_room(i, l.rooms), head);
	return (NULL);
}

t_connect		*find_path(int s, t_lem_in l)
{
	int f;
	t_connect *t;
	static t_connect *head;
	
	f = find_finish_num_room(l);
	if (!head || s == find_start_num_room(l))
		head = new_connect(find_name_room(s, l.rooms));
	t = head;
	while (t->next)
		t = t->next;
	if (s != find_start_num_room(l))
	{
		t->next = new_connect(find_name_room(s, l.rooms));
		t = t->next;
	}
	if (s == f)
	{
		clear_con(find_name_room(s, l.rooms), head);
		return (cmp_arr_con(head, l) ? head : NULL);
	}
	return (finding(l, head, t, s));
}
