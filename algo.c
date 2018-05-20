#include "lem_in.h"
#include <stdio.h>

t_connect			*new_connect(char *s)
{
	t_connect		*t;

	if (!(t = (t_connect *)malloc(sizeof(t_connect))))
		return (NULL);
	if (!(t->r = ft_strdup(s)))
	{
		free(t);
		return (NULL);
	}
	t->next = NULL;
	return (t);
}

int cmp_connects(t_connect *tmp1, t_connect *tmp2, int f, t_lem_in l)
{
	t_connect *t1 = tmp1;
	t_connect *t2 = tmp2;

	if (!tmp1 || !tmp2)
	{
		return (1);
	}
	if (!(tmp1->r) || !(tmp2->r))
	{
		return (1);
	}
//	 printf("------------\n");
//	 printf("tmp1\n");
//	 print_connect(tmp1);
//	 printf("------------\n");
//	 printf("tmp2\n");
//	 print_connect(tmp2);
//	 printf("------------\n");
	// printf("%s\n", "startcmp");
	// printf("t1 %s\n", tmp1->r);
	// printf("t2 %s\n", tmp2->r);
	while (t1 && t2 && t1->r != find_name_room(f, l.rooms) && t2->r != find_name_room(f, l.rooms))
	{
		//printf("cmp in %s %s %d\n", t1->r, t2->r, ft_strcmp(t1->r,t2->r));
		if (!ft_strcmp(t1->r,t2->r))
		{
			t1 = t1->next;
			t2 = t2->next;
		}
		else
		{
			//printf("%s\n", "endcmp");
			return (1);
		}
	}
	if (!t1 && !t2)
	{
		return (0);
	}
	if (t2 &&  !ft_strcmp(t2->r,find_name_room(f, l.rooms)))
	{
		return (0);
	}
	return (1);
}

int cmp_arr_con(t_connect *t, t_connect_arr *tmp_arr, int f, t_lem_in l)
{
	t_connect *tmp;
	t_connect_arr *arr;

	tmp = t;
	arr = tmp_arr;
	//printf("%s\n", "cmpring");
	//print_connect(t);
	if (!arr)
	{
		return (1);
	}
	while (arr)
	{
		if (!cmp_connects(tmp, arr->s, f, l))
			return (0);
		else
			arr = arr->next;
	}
	return (1);
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

int			has_cycle(char *s, t_connect *t)
{
	//printf("%s\n", s);
	while (t)
	{
		if (!ft_strcmp(s, t->r))
		{
			//printf("%d\n", 1);
			return (1);
		}
		t = t->next;
	}
	//printf("%d\n", 0);
	return (0);
}

void		clear(t_connect *t)
{
	t_connect *tmp;
	while (t)
	{
		tmp = t;
		t = t->next;
		free(tmp->r);
		free(tmp);
	}
}

void		clear_con(char *s, t_connect *t)
{
	t_connect *tmp;
	t_connect *tmp1;

    if (!s || !t)
        return ;
	tmp = t;
	while (tmp && tmp->next)
	{
		if (!ft_strcmp(s, tmp->next->r))
		{
			tmp1 = tmp->next;
			tmp->next = tmp->next->next;
			free(tmp1);
		}
		tmp = tmp->next;
	}
}

int	find_path(int s, int f, t_lem_in l, t_connect_arr *arr, t_connect *tmp, int ss)
{
	int j = 0;
	int i = s;
	t_connect *t;
	static t_connect *head;

	if (!head || s == ss)
		head = tmp;
	t = head;
	while (t->next)
		t = t->next;
	t->next = new_connect(find_name_room(s, l.rooms));
	t = t->next;
	if (i == f && cmp_arr_con(head, arr, f, l))
	{
        clear_con(find_name_room(i, l.rooms), head);
		return (1);
	}
    if (i == f && !cmp_arr_con(head, arr, f, l))
    {
        clear_con(find_name_room(i, l.rooms), head);
        return (0);
    }
	while (l.con[i][j])
	{
		if (l.con[i][j] == '1')
		{
			if (has_cycle(find_name_room(j, l.rooms), head))
			{
				//printf("%s\n", "cond1");
				j++;
			}
			else if (j == f && cmp_arr_con(head, arr, f, l))
			{
				//printf("%s\n", "cond2");
				t->next = new_connect(find_name_room(j, l.rooms));
				t = t->next;
				return (1);
			}
			else if (j == f && (!cmp_arr_con(head, arr, f, l)))
			{
				//printf("%s\n", "cond3");
              	clear_con(find_name_room(i, l.rooms), head);
				return (0);
			}
			else if (find_path(j, f, l, arr, tmp, ss))
			{
				//printf("%s\n", "cond4");
				t->next = new_connect(find_name_room(j, l.rooms));
				t = t->next;
				//printf("BBBBB %s\n",t->r);
				//head = NULL;
				return (1);
			}
			else
			{
				//printf("CLEARING %d\n", j);
				clear_con(find_name_room(j, l.rooms), head);
				j++;
			}
		}
		else
			j++;
	}
	return (0);
}

t_connect		*connects(int i, int f, t_lem_in l, t_connect_arr *arr)
{
	t_connect *t;
	t_connect *tmp;
	int j;

	j = 0;
	tmp = new_connect(find_name_room(i, l.rooms));
	t = tmp;
	while (i != f)
	{
		j = 0;
		while (l.con[i][j])
		{
			if (l.con[i][j] == '1' && !has_cycle(find_name_room(j, l.rooms), tmp) 
				&& find_path(j, f, l, arr, tmp, j))
			{
				t->next = new_connect(find_name_room(j, l.rooms));
				t = t->next;
				break;
			}
			else
				j++;
		}
		if (!l.con[i][j])
		{
			clear(tmp);
			return (NULL);
		}
		if (j == f){
			return (tmp);
		}
		i = j;
	}
	return (tmp);
}

