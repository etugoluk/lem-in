#include "lem_in.h"

t_connect_arr		*create_con_arr(t_connect *t)
{
	t_connect_arr	*arr;
	if (!t)
		return (NULL);
	arr = (t_connect_arr *)malloc(sizeof(t_connect_arr));
	arr->s = t;
	arr->next = NULL;
	arr->length = length_connect(t);
	return (arr);
}

void	sort_connects(t_connect_arr *arr)
{
	t_connect_arr *tmp;
	t_connect *tmp1;
	int tmp_length = 0;

	tmp = arr;
	while (tmp && tmp->next)
	{
 		if (tmp->length > tmp->next->length)
		{
			tmp_length = tmp->length;
			tmp->length = tmp->next->length;
			tmp->next->length = tmp_length;
			tmp1 = tmp->s;
			tmp->s = tmp->next->s;
			tmp->next->s = tmp1;
			tmp = arr;
		}
		else
			tmp = tmp->next;
 	}
}

void				print_list(t_list *lst)
{
	while (lst)
	{
		printf("%s\n", lst->content);
		lst = lst->next;
	}
	printf("\n");
}

int					array_of_path(t_lem_in 	t, t_list *lst)
{
	t_connect_arr	*tmp_arr;
	t_connect		*con;

	t.arr = NULL;
	if (!(t.arr = create_con_arr(find_path(find_start_num_room(t), t))))
		return (0);
	tmp_arr = t.arr;
	while ((con = find_path(find_start_num_room(t), t)))
	{
		tmp_arr->next = create_con_arr(con);
		tmp_arr = tmp_arr->next;
	}
	length_arr_connect(t.arr);
	print_arr_connect(t.arr);
	sort_connects(t.arr);
	print_arr_connect(t.arr);
	print_list(lst);
	cross(t);
	free_connect(con);
	return (1);
}
