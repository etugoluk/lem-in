/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_connects.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etugoluk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 11:45:14 by etugoluk          #+#    #+#             */
/*   Updated: 2018/05/25 11:45:14 by etugoluk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		find_second_coord(char *line, t_room *tmp, t_coord *c)
{
	int		size;
	char	*s;

	size = 0;
	s = line;
	while (*line != '\0')
	{
		size++;
		line++;
	}
	while (tmp)
		if (!ft_strncmp(tmp->name, s, size))
		{
			(*c).y = tmp->number;
			break ;
		}
		else
			tmp = tmp->next;
}

t_coord		find_coord(char *line, t_lem_in t)
{
	t_coord	c;
	int		size;
	t_room	*tmp;

	size = 0;
	c.x = -1;
	c.y = -1;
	tmp = t.rooms;
	while (*line != '-')
	{
		size++;
		line++;
	}
	while (tmp)
		if (!ft_strncmp(tmp->name, line - size, size))
		{
			c.x = tmp->number;
			break ;
		}
		else
			tmp = tmp->next;
	find_second_coord(line + 1, t.rooms, &c);
	return (c);
}

char		**symmetry(char **s)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			if (s[i][j] == '1')
				s[j][i] = '1';
			j++;
		}
		i++;
	}
	return (s);
}

int			fill_coord(char *l, t_coord *c, t_lem_in *t)
{
	if (l[0] == '#')
	{
		add_lst(l, t);
		free(l);
		return (1);
	}
	*c = find_coord(l, *t);
	if ((*c).x == -1 || (*c).y == -1 ||
		(*t).con[(*c).x][(*c).y] == '1' || (*c).x == (*c).y ||
		(*t).con[(*c).y][(*c).x] == '1')
		return (0);
	add_lst(l, t);
	(*t).con[(*c).x][(*c).y] = '1';
	free(l);
	return (1);
}

int			fill_arr(t_lem_in *t, char *l)
{
	t_coord	c;

	add_lst(l, t);
	if (ft_strchr(l, '-'))
	{
		c = find_coord(l, *t);
		if ((*t).con[c.x][c.y] == '1' || c.x == c.y)
			return (1);
		(*t).con[c.x][c.y] = '1';
	}
	else if (l[0] != '#')
		return (0);
	while (get_next_line(0, &l) == 1)
		if (!ft_strlen(l) || !fill_coord(l, &c, t))
		{
			free(l);
			break ;
		}
	(*t).con = symmetry((*t).con);
	return (1);
}
