/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clearing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etugoluk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 11:44:26 by etugoluk          #+#    #+#             */
/*   Updated: 2018/05/25 11:44:27 by etugoluk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void				free_arr(char **arr)
{
	int				i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		ft_strdel(&arr[i]);
		i++;
	}
	free(arr);
}

void				free_rooms(t_room *r)
{
	t_room			*tmp;

	while (r)
	{
		tmp = r;
		r = r->next;
		free(tmp->name);
		free(tmp);
	}
}

void				free_connect(t_con *c)
{
	t_con			*tmp;

	while (c)
	{
		tmp = c;
		c = c->next;
		free(tmp->r);
		free(tmp);
	}
}

void				free_arr_connect(t_con_arr *c)
{
	t_con_arr		*tmp;

	while (c)
	{
		tmp = c;
		c = c->next;
		free_connect(tmp->s);
		free(tmp);
	}
}

void				free_ants(t_ant *c)
{
	t_ant			*tmp;

	while (c)
	{
		tmp = c;
		c = c->next;
		free(tmp);
	}
}
