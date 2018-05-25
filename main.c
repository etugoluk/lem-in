#include "lem_in.h"

void			free_struct(t_lem_in *t, char *line)
{
	free(line);
	free_arr_connect(t->arr);
	free_arr(t->con);
	free_rooms(t->rooms);
	free_ants(t->ants);
}

int				main()
{
	int			fd;
	char		*line;
	t_lem_in	t;
	t_list		*lst;
	t_list		*head;

	fd = open("file", O_RDONLY);
	//fd = 0;
	get_next_line(fd, &line);
	t.sum_ants = ft_atoi(line);
	head = ft_lstnew(line, ft_strlen(line));
	lst = head;
	free(line);
	if (ft_strcmp(line, ft_itoa(t.sum_ants)) || t.sum_ants <= 0)
	{
		printf("error\n");
		return(0);
	}
	free(line);
	if ((!(line = read_rooms(&t, fd, &lst))) || (!ft_strchr(line, '-') && line[0] != '#') || 
		(!(t.con = connect_array(t.numb_rooms))) || ((!fill_connect_array(fd, &t, line, &lst)) || 
		(!(t.ants = fill_ants(t))) || (!(array_of_path(t, head)))))
	{
		printf("error\n");
		return(0);
	}
	free_struct(&t, line);
	// while (1)
	// {}
	return (0);
}
