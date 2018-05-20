#include "lem_in.h"

t_ant   *fill_ants(t_lem_in t)
{
    t_ant   *tmp_ant;
    t_ant   *ant;
    int     i;
    int     k = find_start_num_room(t);

    i = 0;
    ant = (t_ant *)malloc(sizeof(t_ant));
    ant->number = i;
    ant->room = k;
    ant->next = NULL;
    tmp_ant = ant;
    i++;
    while (i < t.sum_ants)
    {
        tmp_ant->next = (t_ant *)malloc(sizeof(t_ant));
        tmp_ant->next->number = i;
        tmp_ant->next->room = k;
        tmp_ant->next->next = NULL;
        tmp_ant = tmp_ant->next;
        i++;
    }
    return (ant);
}

int		main()
{
	int 		fd;
	char 		*line;
	t_lem_in 	t;

	fd = open("file22", O_RDONLY);
	if (fd < 0) {
		printf("error1\n");
		return(0);
	}
	//fd = 0;
	get_next_line(fd, &line);
	t.sum_ants = ft_atoi(line);
	if (ft_strcmp(line, ft_itoa(t.sum_ants)) || !t.sum_ants)
	{
		printf("error2\n");
		return(0);
	}
	if (!(line = read_rooms(&t, fd)) || !find_start_room(t) || !find_finish_room(t))
	{
		printf("error3\n");
		return(0);
	}
	// while (1)
	// {}
	if (!ft_strchr(line, '-') && line[0] != '#')
	{
		printf("error4\n");
		return(0);
	}	
	t.con = connect_array(t.numb_rooms);
	if (!fill_connect_array(fd, &t, line))
	{
		printf("error5\n");
		return(0);
	}
	//printing_connect(t);
    t.ants = fill_ants(t);
    //t_ant *tmp_ants = t.ants;
//    while (tmp_ants)
//    {
//        printf("ant %d %d\n", tmp_ants->number, tmp_ants->room);
//        tmp_ants = tmp_ants->next;
//    }
    if (!(array_of_path(t)))
    {
    	printf("error6\n");
		return(0);
    }
   // free_struct(&t);
    return (0);
}
