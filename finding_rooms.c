/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finding_rooms.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etugoluk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 11:44:43 by etugoluk          #+#    #+#             */
/*   Updated: 2018/05/25 11:44:44 by etugoluk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			snroom(t_lem_in t)
{
	t_room	*r;
	int		res;
	int		i;

	i = 0;
	res = -1;
	r = NULL;
	if (t.rooms)
		r = t.rooms;
	while (r)
	{
		if (r->start)
		{
			res = r->number;
			i++;
		}
		r = r->next;
	}
	return ((i == 1) ? res : -1);
}

int			fnroom(t_lem_in t)
{
	t_room	*r;
	int		res;
	int		i;

	i = 0;
	res = -1;
	r = NULL;
	if (t.rooms)
		r = t.rooms;
	while (r)
	{
		if (r->finish)
		{
			res = r->number;
			i++;
		}
		r = r->next;
	}
	return ((i == 1) ? res : -1);
}

int			find_number_room(char *s, t_room *t)
{
	int		n;

	n = 0;
	while (t)
	{
		if (!ft_strcmp(t->name, s))
		{
			n = t->number;
			break ;
		}
		else
			t = t->next;
	}
	return (n);
}

char		*find_name_room(int n, t_room *t)
{
	char	*name;

	name = NULL;
	while (t)
	{
		if (t->number == n)
		{
			name = t->name;
			break ;
		}
		else
			t = t->next;
	}
	return (name);
}

t_room		*find_number(t_room *t, int n)
{
	while (t)
	{
		if (t->number == n)
			break ;
		else
			t = t->next;
	}
	return (t);
}
