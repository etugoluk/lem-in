#ifndef LEM_IN_H
# define LEM_IN_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft/libft.h"
#include <stdio.h>

typedef struct	s_coord
{
	int	x;
	int	y;
}				t_coord;

typedef struct			s_room
{
	int				number;
	char			*name;
	int				start;
	int				finish;
	struct s_room	*next;
	int				x;
	int				y;
	int				num_ants;
	
}						t_room;

typedef struct			s_ant
{
    int                 number;
    int                 room;
    struct		s_ant   *next;
}						t_ant;

typedef struct			s_connect
{
	char				*r;
	struct s_connect	*next;
}						t_connect;

typedef struct				s_connect_arr
{
	struct s_connect		*s;
	int						length;
	struct s_connect_arr	*next;
}							t_connect_arr;

typedef struct			s_path_ant
{
    int                 number;
    int                 step;
    t_connect           *path;
    struct	s_path_ant  *next;
}						t_path_ant;


typedef struct			s_lem_in
{
	int					sum_ants;
	int					numb_rooms;
	struct s_room		*rooms;
	//struct s_connect	*connects;
	char				**con;
    struct s_ant        *ants;
}						t_lem_in;

int				digits(int n);
t_room	*create_room(char *line, int k, int num);
t_coord		find_coord(char *line, t_lem_in t);
int		check(char *s, t_room *t);
char	**symmetry(char **s);
char		**connect_array(int numb_rooms);
int	fill_connect_array(int fd, t_lem_in *t, char *line);
char	*read_rooms(t_lem_in *t, int fd);
t_connect_arr	*create_con_arr(t_connect *t);
int    array_of_path(t_lem_in 	t);
t_ant   *fill_ants(t_lem_in t);
void	free_arr(char **arr);
void	free_rooms(t_room *r);
void free_struct(t_lem_in *t);



char	*find_start_room(t_lem_in 	t);
char	*find_finish_room(t_lem_in 	t);
int		find_number_room(char *s, t_room *t);
char	*find_name_room(int n, t_room *t);
int		find_start_num_room(t_lem_in 	t);
int		find_finish_num_room(t_lem_in 	t);
t_room  *find_number(t_room *tmp, int n);
t_room  *find_name(t_room *tmp, char *n);
int	find_path(int s, int f, t_lem_in l, t_connect_arr *arr, t_connect *tmp, int ss);
t_connect		*connects(int i, int f, t_lem_in l, t_connect_arr *arr);
void	printing_connect(t_lem_in t);
void	print_connect(t_connect *t);
void	print_arr_connect(t_connect_arr *arr);
int		length_connect(t_connect *t);
void	sort_connects(t_connect_arr *arr);
void	length_arr_connect(t_connect_arr *arr);
void    cross_array(t_connect_arr *arr_tmp, t_lem_in l);
char *find_room(t_lem_in    t, t_connect_arr *arr, t_ant *ant);
void cross(t_lem_in l, t_connect_arr *arr);


#endif
