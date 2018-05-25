#include "lem_in.h"

char		**connect_array(int numb_rooms)
{
	char 	**t;
	int		i;
	int		j;

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

t_coord		find_coord(char *line, t_lem_in t)
{
	t_coord	c;
	int		size;

	size = 0;
	c.x = -1;
	c.y = -1;
	t_room *tmp;
	char *s;
	s = line;
	while (*line != '-')
	{
		size++;
		line++;
	}
	tmp = t.rooms;
	while (tmp)
	{
		if (!ft_strncmp(tmp->name, s, size))
		{
			c.x = tmp->number;
			break;
		}
		else
			tmp = tmp->next;
	}
	line++;
	size = 0;
	s = line;
	while (*line != '\0')
	{
		size++;
		line++;
	}
	tmp = t.rooms;
	while (tmp)
	{
		if (!ft_strncmp(tmp->name, s, size))
		{
			c.y = tmp->number;
			break;
		}
		else
			tmp = tmp->next;
	}
	return (c);
}

char	**symmetry(char **s)
{
	int i = 0;
	int j = 0;
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

int	fill_connect_array(int fd, t_lem_in *t, char *line, t_list **lst)
{
	t_coord cord;

	(*lst)->next = ft_lstnew(line, ft_strlen(line));
	*lst = (*lst)->next;
	if (ft_strchr(line, '-'))
	{
		cord = find_coord(line, *t);
		if (cord.x == -1 || cord.y == -1)
			return (0);
		(*t).con[cord.x][cord.y] = '1';
	}
	else if (line[0] != '#')
		return (0);
	while (get_next_line(fd, &line) == 1 && (ft_strchr(line, '-') || line[0] == '#'))
	{
		if (line[0] == '#')
		{
			free(line);
			continue;
		}
		(*lst)->next = ft_lstnew(line, ft_strlen(line));
		*lst = (*lst)->next;
		cord = find_coord(line, *t);
		if (cord.x == -1 || cord.y == -1)
			return (0);
		(*t).con[cord.x][cord.y] = '1';
		free(line);
	}
	(*t).con = symmetry((*t).con);
	return (1);
}
