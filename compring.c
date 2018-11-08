/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etugoluk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 14:45:55 by etugoluk          #+#    #+#             */
/*   Updated: 2018/05/26 14:45:56 by etugoluk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				cmp_con(t_con *t1, t_con *t2, int f, t_lem_in l)
{
	if (!t1 || !t2 || !(t1->r) || !(t2->r))
		return (1);
	while (t1 && t2 && t1->r != find_name_room(f, l.rooms)
		&& t2->r != find_name_room(f, l.rooms))
	{
		if (!ft_strcmp(t1->r, t2->r))
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

int				cmp_arr_con(t_con *t, t_lem_in l)
{
	int			f;

	f = fnroom(l);
	if (!(l.arr))
		return (1);
	while (l.arr)
	{
		if (!cmp_con(t, (l.arr)->s, f, l))
			return (0);
		else
			l.arr = (l.arr)->next;
	}
	return (1);
}
