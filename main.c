/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etugoluk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 11:43:50 by etugoluk          #+#    #+#             */
/*   Updated: 2018/05/25 11:43:54 by etugoluk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			free_struct(t_lem_in *t)
{
	free_arr_connect(t->arr);
	free_arr(t->con);
	free_rooms(t->rooms);
	free_ants(t->ants);
}

void			add_lst(char *l, t_lem_in *t)
{
	(*t).lst->next = ft_lstnew(l, ft_strlen(l) + 1);
	(*t).lst = (*t).lst->next;
}

int				start_comments(char *l, t_lem_in *t, char *tmp)
{
	free(l);
	if (l[0] != '#')
	{
		(*t).sum_ants = ft_atoi(l);
		tmp = ft_itoa((*t).sum_ants);
		if ((ft_strcmp(tmp, (*t).lst->content) || (*t).sum_ants <= 0))
		{
			free(tmp);
			return (0);
		}
		else
			return (1);
	}
	while (get_next_line(0, &l) > 0 && l[0] == '#')
	{
		add_lst(l, t);
		free(l);
	}
	if (ft_strcmp(tmp, l))
		free(l);
	add_lst(l, t);
	(*t).sum_ants = ft_atoi(l);
	tmp = ft_itoa((*t).sum_ants);
	free(tmp);
	return (((ft_strcmp(l, tmp) || (*t).sum_ants <= 0)) ? 0 : 1);
}

int				main(void)
{
	int			g;
	char		*l;
	t_lem_in	t;
	t_list		*head;

	l = NULL;
	g = get_next_line(0, &l);
	head = ft_lstnew(l, ft_strlen(l) + 1);
	t.lst = head;
	t.rooms = NULL;
	t.numb_rooms = 0;
	if ((g != 1) || (!(start_comments(l, &t, t.lst->content))) ||
		(!(l = read_r(&t, l, g, l))) ||
		(!(t.con = connect_array(t.numb_rooms))) ||
		((!fill_arr(&t, l)) ||
		(!(t.ants = fill_ants(t))) || (!(array_of_path(t, head)))))
	{
		ft_printf("ERROR\n");
		free_struct(&t);
		return (0);
	}
	free_struct(&t);
	return (0);
}
