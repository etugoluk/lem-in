/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crossing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etugoluk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 11:44:36 by etugoluk          #+#    #+#             */
/*   Updated: 2018/05/25 11:44:37 by etugoluk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				ft_length(t_con *con)
{
	int			i;

	i = 0;
	while (con)
	{
		i++;
		con = con->next;
	}
	return (i);
}

t_room			*find_name(t_room *t, char *n)
{
	while (t)
	{
		if (!ft_strcmp(t->name, n))
			break ;
		else
			t = t->next;
	}
	return (t);
}

char			*find_room(t_lem_in t, t_ant *ant, int check)
{
	t_con		*tmp_con;

	while (t.arr)
	{
		tmp_con = (t.arr)->s;
		while (tmp_con)
		{
			if ((find_number_room(tmp_con->r, t.rooms) == ant->room))
			{
				if ((tmp_con->next) &&
					(find_name(t.rooms, tmp_con->next->r)->num_ants == 0 ||
					find_name(t.rooms, tmp_con->next->r)->finish == 1))
					return (ft_length(tmp_con->next) > check + 1 ?
						find_name_room(ant->room, t.rooms) : tmp_con->next->r);
				else if ((tmp_con->next) &&
					(find_name(t.rooms, tmp_con->next->r)->num_ants))
					check = ft_length(tmp_con->next);
				else
					break ;
			}
			tmp_con = tmp_con->next;
		}
		t.arr = (t.arr)->next;
	}
	return (find_name_room(ant->room, t.rooms));
}

void			find_cross(t_ant *t_a, t_lem_in l, int k, char *t_r)
{
	while (t_a)
	{
		if (t_a->room == fnroom(l))
		{
			t_a = t_a->next;
			continue;
		}
		t_r = find_room(l, t_a, l.numb_rooms);
		find_name(l.rooms, find_name_room(t_a->room, l.rooms))->num_ants--;
		if (ft_strcmp(t_r, find_name_room(t_a->room, l.rooms)))
		{
			if (k == 1)
				ft_printf(" ");
			ft_printf("L%d-%s", t_a->number, t_r);
			k = 1;
		}
		t_a->room = find_number_room(t_r, l.rooms);
		find_name(l.rooms, find_name_room(t_a->room, l.rooms))->num_ants++;
		t_a = t_a->next;
	}
}

void			cross(t_lem_in l)
{
	char		*tmp_room;
	t_ant		*tmp_ant;
	t_room		*r;

	tmp_room = NULL;
	r = find_number(l.rooms, fnroom(l));
	while (r->num_ants != l.sum_ants)
	{
		tmp_ant = l.ants;
		find_cross(tmp_ant, l, 0, tmp_room);
		ft_printf("\n");
	}
}
