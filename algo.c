/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etugoluk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 11:44:00 by etugoluk          #+#    #+#             */
/*   Updated: 2018/05/25 11:44:01 by etugoluk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				has_cycle(char *s, t_con *t)
{
	while (t)
	{
		if (!ft_strcmp(s, t->r))
			return (1);
		t = t->next;
	}
	return (0);
}

void			clear_con(char *s, t_con *t)
{
	t_con		*tmp;
	t_con		*tmp1;

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

t_con			*finding(t_lem_in l, t_con *head, t_con *t, t_coord c)
{
	while (l.con[c.x][c.y])
		if (l.con[c.x][c.y] == '1')
		{
			if (has_cycle(find_name_room(c.y, l.rooms), head))
				c.y++;
			else if (c.y == fnroom(l) && cmp_arr_con(head, l))
			{
				t->next = new_connect(find_name_room(c.y, l.rooms));
				return (head);
			}
			else if (c.y == fnroom(l) && (!cmp_arr_con(head, l)))
			{
				clear_con(find_name_room(c.x, l.rooms), head);
				return (NULL);
			}
			else if (find_path(c.y, l))
				return (head);
			else
				c.y++;
		}
		else
			c.y++;
	clear_con(find_name_room(c.x, l.rooms), head);
	return (NULL);
}

t_con			*find_path(int s, t_lem_in l)
{
	int					f;
	t_con				*t;
	static t_con		*head;
	t_coord				c;

	f = fnroom(l);
	c.x = s;
	c.y = 0;
	if (!head || s == snroom(l))
		head = new_connect(find_name_room(s, l.rooms));
	t = head;
	while (t->next)
		t = t->next;
	if (s != snroom(l))
	{
		t->next = new_connect(find_name_room(s, l.rooms));
		t = t->next;
	}
	if (s == f)
	{
		clear_con(find_name_room(s, l.rooms), head);
		return (cmp_arr_con(head, l) ? head : NULL);
	}
	return (finding(l, head, t, c));
}
