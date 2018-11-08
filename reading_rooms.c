/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_rooms.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etugoluk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 11:45:22 by etugoluk          #+#    #+#             */
/*   Updated: 2018/05/25 11:45:23 by etugoluk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			not_double(t_room *r, t_room *tmp)
{
	if (r->name[0] == 'L')
		return (0);
	while (tmp)
	{
		if (!ft_strcmp(r->name, tmp->name) ||
			((r->x == tmp->x) && (r->y == tmp->y)))
			break ;
		tmp = tmp->next;
	}
	return ((!(tmp->next)) ? 1 : 0);
}

int			add_room(t_lem_in *t, char *l, int p, t_room **tmp)
{
	if (!(*t).numb_rooms)
	{
		if (!((*t).rooms = create_room(l, p, (*t).sum_ants, 0)))
			return (0);
		*tmp = (*t).rooms;
		(*t).rooms->number = (*t).numb_rooms;
	}
	else
	{
		if (!((*t).rooms->next = create_room(l, p, (*t).sum_ants, 0)))
			return (0);
		(*t).rooms = (*t).rooms->next;
		(*t).rooms->number = (*t).numb_rooms;
	}
	free(l);
	return (1);
}

int			room_line(t_lem_in *t, char *l, t_room **tmp, int p)
{
	if (p == 1)
	{
		p = (!ft_strcmp(l, "##start")) ? 1 : 2;
		free(l);
		while (get_next_line(0, &l) > 0 && (l[0] == '#'))
		{
			add_lst(l, t);
			free(l);
		}
	}
	add_lst(l, t);
	if (!add_room(t, l, p, tmp))
	{
		(*t).rooms = *tmp;
		free(l);
		return (0);
	}
	(*t).numb_rooms++;
	if ((not_double((*t).rooms, *tmp)))
		return (1);
	else
	{
		(*t).rooms = *tmp;
		return (0);
	}
}

char		*read_r(t_lem_in *t, char *l, int g, char *old)
{
	t_room	*tmp;

	tmp = NULL;
	while ((g = get_next_line(0, &l)) > 0 &&
		(ft_strchr(l, ' ') || ft_strchr(l, '#')))
		if (!ft_strcmp(l, "##start") || (!ft_strcmp(l, "##end")))
		{
			add_lst(l, t);
			if (!room_line(t, l, &tmp, 1))
				return (NULL);
		}
		else if (l[0] == '#')
		{
			add_lst(l, t);
			free(l);
		}
		else if (!room_line(t, l, &tmp, 0))
			return (NULL);
	(*t).rooms = tmp;
	if ((!tmp && ft_strcmp(l, old)) || ((!ft_strchr(l, '-'))
		&& g == 1) || (snroom(*t) == -1 || fnroom(*t) == -1))
		free(l);
	return ((g == 1) && (!tmp || (snroom(*t) == -1 ||
		fnroom(*t) == -1)) ? NULL : l);
}
