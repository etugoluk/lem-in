/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creating.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etugoluk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 17:38:47 by etugoluk          #+#    #+#             */
/*   Updated: 2018/05/25 17:38:49 by etugoluk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_ant			*fill_ants(t_lem_in t)
{
	t_ant		*ant;
	t_ant		*tmp_ant;
	int			i;

	i = 1;
	ant = (t_ant *)malloc(sizeof(t_ant));
	ant->number = i;
	ant->room = snroom(t);
	ant->next = NULL;
	tmp_ant = ant;
	i++;
	while (i <= t.sum_ants)
	{
		tmp_ant->next = (t_ant *)malloc(sizeof(t_ant));
		tmp_ant->next->number = i;
		tmp_ant->next->room = ant->room;
		tmp_ant->next->next = NULL;
		tmp_ant = tmp_ant->next;
		i++;
	}
	return (ant);
}

int				coords(t_room **room, char *line, int size)
{
	char		*txt;

	(*room)->x = ft_atoi(line + size);
	txt = ft_itoa((*room)->x);
	if (ft_strncmp(line + size + 1, txt, ft_strlen(txt)))
	{
		free(txt);
		return (0);
	}
	free(txt);
	(*room)->y = ft_atoi(line + size + digits((*room)->x) + 1);
	txt = ft_itoa((*room)->y);
	if (ft_strcmp(line + size + digits((*room)->x) + 2, txt))
	{
		free(txt);
		return (0);
	}
	free(txt);
	return (1);
}

t_con			*new_connect(char *s)
{
	t_con		*t;

	if (!(t = (t_con *)malloc(sizeof(t_con))))
		return (NULL);
	if (!(t->r = ft_strdup(s)))
	{
		free(t);
		return (NULL);
	}
	t->next = NULL;
	return (t);
}

t_room			*create_room(char *line, int k, int num, int size)
{
	int			i;
	t_room		*room;

	i = -1;
	room = (t_room *)malloc(sizeof(t_room));
	while (line[size] && line[size] != ' ')
		size++;
	if (!line[size])
	{
		free(room);
		return (NULL);
	}
	room->name = ft_strnew(size);
	while (++i < size)
		room->name[i] = line[i];
	room->num_ants = (k == 1) ? num : 0;
	if (!(coords(&room, line, size)))
	{
		free_rooms(room);
		return (NULL);
	}
	room->start = (k == 1) ? 1 : 0;
	room->finish = (k == 2) ? 1 : 0;
	room->next = NULL;
	return (room);
}

char			**connect_array(int numb_rooms)
{
	char		**t;
	int			i;
	int			j;

	i = 0;
	j = 0;
	t = (char **)malloc(sizeof(char *) * (numb_rooms + 1));
	t[numb_rooms] = 0;
	while (i < numb_rooms)
		t[i++] = ft_strnew(numb_rooms);
	i = 0;
	while (i < numb_rooms)
	{
		j = 0;
		while (j < numb_rooms)
			t[i][j++] = '0';
		t[i][j] = '\0';
		i++;
	}
	return (t);
}
