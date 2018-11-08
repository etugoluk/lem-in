/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etugoluk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 11:44:55 by etugoluk          #+#    #+#             */
/*   Updated: 2018/05/25 11:44:56 by etugoluk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft/libft.h"

typedef struct			s_coord
{
	int					x;
	int					y;
}						t_coord;

typedef struct			s_room
{
	int					number;
	char				*name;
	int					start;
	int					finish;
	struct s_room		*next;
	int					x;
	int					y;
	int					num_ants;
}						t_room;

typedef struct			s_ant
{
	int					number;
	int					room;
	struct s_ant		*next;
}						t_ant;

typedef struct			s_con
{
	char				*r;
	struct s_con		*next;
}						t_con;

typedef struct			s_con_arr
{
	struct s_con		*s;
	int					length;
	struct s_con_arr	*next;
}						t_con_arr;

typedef struct			s_lem_in
{
	int					sum_ants;
	int					numb_rooms;
	struct s_room		*rooms;
	char				**con;
	struct s_ant		*ants;
	struct s_con_arr	*arr;
	t_list				*lst;
}						t_lem_in;

void					add_lst(char *l, t_lem_in *t);
int						start_comments(char *l, t_lem_in *t, char *tmp);
char					*read_r(t_lem_in *t, char *l, int g, char *old);
t_room					*create_room(char *line, int k, int num, int size);
int						room_line(t_lem_in *t, char *l, t_room **tmp, int p);
int						add_room(t_lem_in *t, char *l, int p, t_room **tmp);
int						coords(t_room **room, char *line, int size);
int						not_double(t_room *r, t_room *tmp);
t_con					*new_connect(char *s);
char					**connect_array(int numb_rooms);
int						fill_arr(t_lem_in *t, char *l);
int						fill_coord(char *l, t_coord *c, t_lem_in *t);
char					**symmetry(char **s);
t_coord					find_coord(char *line, t_lem_in t);
void					find_second_coord(char *line, t_room *tmp, t_coord *c);
t_ant					*fill_ants(t_lem_in t);
int						array_of_path(t_lem_in t, t_list *lst);
void					print_list(t_list *lst);
void					sort_connects(t_con_arr *arr);
t_con_arr				*create_con_arr(t_con *t);
int						cmp_arr_con(t_con *t, t_lem_in l);
int						cmp_con(t_con *t1, t_con *t2, int f, t_lem_in l);
t_con					*find_path(int s, t_lem_in l);
t_con					*finding(t_lem_in l, t_con *head, t_con *t, t_coord c);
void					clear_con(char *s, t_con *t);
int						has_cycle(char *s, t_con *t);
void					cross(t_lem_in l);
void					find_cross(t_ant *t_a, t_lem_in l, int k, char *t_r);
char					*find_room(t_lem_in t, t_ant *ant, int check);
t_room					*find_name(t_room *t, char *n);
int						ft_length(t_con *con);
int						snroom(t_lem_in t);
int						fnroom(t_lem_in t);
int						find_number_room(char *s, t_room *t);
char					*find_name_room(int n, t_room *t);
t_room					*find_number(t_room *t, int n);
void					free_arr(char **arr);
void					free_rooms(t_room *r);
void					free_connect(t_con *c);
void					free_arr_connect(t_con_arr *c);
void					free_ants(t_ant *c);
void					free_struct(t_lem_in *t);
void					length_arr_connect(t_con_arr *arr);
int						length_connect(t_con *t);
int						check(char *s, t_room *t);
int						digits(int n);

#endif
