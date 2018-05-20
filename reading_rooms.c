#include "lem_in.h"

t_room	*create_room(char *line, int k, int num)
{
	int 	i;
	int 	size;
	t_room	*room;

	i = 0;
	size = 0;
	room = (t_room *)malloc(sizeof(t_room));
	while (line[size] && line[size] != ' ')
		size++;
	if (!line[size])
		return (NULL);
	room->name = ft_strnew(size);
	while (i < size)
	{
		room->name[i] = line[i];
		i++;
	}
	room->num_ants = num;
	room->x = ft_atoi(line + size);
	if (ft_strncmp(line + size + 1, ft_itoa(room->x), ft_strlen(ft_itoa(room->x))))
	{
		//printf("%s %s\n", line + size + digits(room->x) + 2, ft_itoa(room->y));
		return (NULL);
	}
	room->y = ft_atoi(line + size + digits(room->x) + 1);
	if (ft_strcmp(line + size + digits(room->x) + 2, ft_itoa(room->y)))
	{
		//printf("%s %s\n", line + size + digits(room->x) + 2, ft_itoa(room->y));
		return (NULL);
	}
	room->start = (k == 1) ? 1 : 0;
	room->finish = (k == 2) ? 1 : 0;
	room->next = NULL;
	return (room);
}

char	*read_rooms(t_lem_in *t, int fd)
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
			if (check_start)
				return (NULL);
			get_next_line(fd, &line);
			if (!numb_rooms)
			{
				if (!((*t).rooms = create_room(line, 1, (*t).sum_ants)))
					return (NULL);
				(*t).rooms->number = numb_rooms;
				tmp = (*t).rooms;
			}
			else
			{
				if (!((*t).rooms->next = create_room(line, 1, (*t).sum_ants)))
					return (NULL);
				(*t).rooms = (*t).rooms->next;
				(*t).rooms->number = numb_rooms;
			}
			check_start++;
		}
		else if (!ft_strcmp(line, "##end"))
		{
			if (check_end)
				return (NULL);
			get_next_line(fd, &line);
			if (!numb_rooms)
			{
				if (!((*t).rooms = create_room(line, 2, 0)))
					return (NULL);
				(*t).rooms->number = numb_rooms;
				tmp = (*t).rooms;
			}
			else
			{
				if (!((*t).rooms->next = create_room(line, 2, 0)))
					return (NULL);
				(*t).rooms = (*t).rooms->next;
				(*t).rooms->number = numb_rooms;
			}
			check_end++;
		}
		else if (line[0] == '#')
			continue;
		else
		{
			if (!numb_rooms)
			{
				if (!((*t).rooms = create_room(line, 0, 0)))
					return (NULL);
				tmp = (*t).rooms;
				(*t).rooms->number = numb_rooms;
			}
			else
			{
				if (!((*t).rooms->next = create_room(line, 0, 0)))
					return (NULL);
				(*t).rooms = (*t).rooms->next;
				(*t).rooms->number = numb_rooms;
			}
		}
		numb_rooms++;
	}
	(*t).numb_rooms = numb_rooms;
	(*t).rooms = tmp;
	return (line);
}
