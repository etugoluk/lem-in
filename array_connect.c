/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_connect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etugoluk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 11:44:18 by etugoluk          #+#    #+#             */
/*   Updated: 2018/05/25 11:44:19 by etugoluk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_con_arr			*create_con_arr(t_con *t)
{
	t_con_arr		*arr;

	if (!t)
		return (NULL);
	arr = (t_con_arr *)malloc(sizeof(t_con_arr));
	arr->s = t;
	arr->next = NULL;
	arr->length = length_connect(t);
	return (arr);
}

void				sort_connects(t_con_arr *arr)
{
	t_con_arr		*tmp;
	t_con			*tmp1;
	int				tmp_length;

	tmp_length = 0;
	tmp = arr;
	while (tmp && tmp->next)
	{
		if (tmp->length > tmp->next->length)
		{
			tmp_length = tmp->length;
			tmp->length = tmp->next->length;
			tmp->next->length = tmp_length;
			tmp1 = tmp->s;
			tmp->s = tmp->next->s;
			tmp->next->s = tmp1;
			tmp = arr;
		}
		else
			tmp = tmp->next;
	}
}

void				print_list(t_list *lst)
{
	while (lst)
	{
		ft_printf("%s\n", lst->content);
		lst = lst->next;
	}
	ft_printf("\n");
}

int					array_of_path(t_lem_in t, t_list *lst)
{
	t_con_arr		*tmp_arr;
	t_con			*con;
	int				s;

	t.arr = NULL;
	s = snroom(t);
	if (!(t.arr = create_con_arr(find_path(s, t))))
		return (0);
	tmp_arr = t.arr;
	while ((con = find_path(s, t)))
	{
		tmp_arr->next = create_con_arr(con);
		tmp_arr = tmp_arr->next;
	}
	length_arr_connect(t.arr);
	sort_connects(t.arr);
	print_list(lst);
	cross(t);
	free_connect(con);
	return (1);
}
