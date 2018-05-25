#include "lem_in.h"

t_room	*create_room(char *line, int k, int num)
{
	int 	i;
	int 	size;
	t_room	*room;
	char 	*txt;

	i = 0;
	size = 0;
	room = (t_room *)malloc(sizeof(t_room));
	while (line[size] && line[size] != ' ')
		size++;
	if (!line[size])
	{
		free(room);
		return (NULL);
	}
	room->name = ft_strnew(size);
	while (i < size)
	{
		room->name[i] = line[i];
		i++;
	}
	room->num_ants = num;
	room->x = ft_atoi(line + size);
	txt = ft_itoa(room->x);
	if (ft_strncmp(line + size + 1, txt, ft_strlen(txt)))
		return (NULL);
	free(txt);
	room->y = ft_atoi(line + size + digits(room->x) + 1);
	txt = ft_itoa(room->y);
	if (ft_strcmp(line + size + digits(room->x) + 2, txt))
		return (NULL);
	free(txt);
	room->start = (k == 1) ? 1 : 0;
	room->finish = (k == 2) ? 1 : 0;
	room->next = NULL;
	return (room);
}

int	room_start_line(t_lem_in *t, int numb_rooms, char *line, t_room	**tmp)
{
	if (!numb_rooms)
	{
		if (!((*t).rooms = create_room(line, 1, (*t).sum_ants)))
			return (0);
		(*t).rooms->number = numb_rooms;
		*tmp = (*t).rooms;
	}
	else
	{
		if (!((*t).rooms->next = create_room(line, 1, (*t).sum_ants)))
			return (0);
		(*t).rooms = (*t).rooms->next;
		(*t).rooms->number = numb_rooms;
	}
	return (1);
}

int	room_finish_line(t_lem_in *t, int numb_rooms, char *line, t_room **tmp)
{
	if (!numb_rooms)
	{
		if (!((*t).rooms = create_room(line, 2, 0)))
			return (0);
		(*t).rooms->number = numb_rooms;
		*tmp = (*t).rooms;
	}
	else
	{
		if (!((*t).rooms->next = create_room(line, 2, 0)))
			return (0);
		(*t).rooms = (*t).rooms->next;
		(*t).rooms->number = numb_rooms;
	}
	return (1);
}

int	room_line(t_lem_in *t, int numb_rooms, char *line, t_room	**tmp)
{
	if (!numb_rooms)
	{
		if (!((*t).rooms = create_room(line, 0, 0)))
			return (0);
		*tmp = (*t).rooms;
		(*t).rooms->number = numb_rooms;
	}
	else
	{
		if (!((*t).rooms->next = create_room(line, 0, 0)))
			return (0);
		(*t).rooms = (*t).rooms->next;
		(*t).rooms->number = numb_rooms;
	}
	return (1);
}

char	*read_rooms(t_lem_in *t, int fd, t_list	**lst)
{
	t_room		*tmp;
	int			numb_rooms;
	char		*line;
	int			check_start = 0;
	int			check_end = 0;

	numb_rooms = 0;
	while (get_next_line(fd, &line) == 1 && (ft_strchr(line, ' ') || ft_strchr(line, '#')))
	{
		if (!ft_strcmp(line, "##start"))
		{
			(*lst)->next = ft_lstnew(line, ft_strlen(line));
			*lst = (*lst)->next;
			free(line);
			if (check_start)
				return (NULL);
			get_next_line(fd, &line);
			(*lst)->next = ft_lstnew(line, ft_strlen(line));
			*lst = (*lst)->next;
			if (!room_start_line(t, numb_rooms, line, &tmp))
				return (NULL);
			check_start++;
		}
		else if (!ft_strcmp(line, "##end"))
		{
			(*lst)->next = ft_lstnew(line, ft_strlen(line));
			*lst = (*lst)->next;
			free(line);
			if (check_end)
				return (NULL);
			get_next_line(fd, &line);
			(*lst)->next = ft_lstnew(line, ft_strlen(line));
			*lst = (*lst)->next;
			if (!room_finish_line(t, numb_rooms, line, &tmp))
				return (NULL);
			check_end++;
		}
		else if (line[0] == '#')
		{
			free(line);
			continue;
		}
		else
		{
			(*lst)->next = ft_lstnew(line, ft_strlen(line));
			*lst = (*lst)->next;
			if (!room_line(t, numb_rooms, line, &tmp))
				return (NULL);
		}
		free(line);
		numb_rooms++;
	}
	(*t).numb_rooms = numb_rooms;
	(*t).rooms = tmp;
	if (!check_start || !check_end)
		return (NULL);
	return (line);
}
