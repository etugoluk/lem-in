/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etugoluk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 11:45:06 by etugoluk          #+#    #+#             */
/*   Updated: 2018/05/25 11:45:07 by etugoluk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				digits(int n)
{
	int			size;
	int			i;

	size = 1;
	i = 1;
	if (n < 0)
	{
		size++;
		n = -n;
	}
	if (n == 0)
		return (1);
	while (n / i > 0)
	{
		size++;
		i *= 10;
	}
	size--;
	return (size);
}

int				check(char *s, t_room *t)
{
	while (t)
	{
		if (!ft_strcmp(s, t->name))
			return (1);
		t = t->next;
	}
	return (0);
}

int				length_connect(t_con *t)
{
	int			n;

	n = 0;
	if (!t)
		return (n);
	while (t)
	{
		n++;
		t = t->next;
	}
	return (n - 1);
}

void			length_arr_connect(t_con_arr *arr)
{
	while (arr)
	{
		arr->length = length_connect(arr->s);
		arr = arr->next;
	}
}
