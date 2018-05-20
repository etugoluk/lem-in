#include "lem_in.h"

int				digits(int n)
{
	int			size;
	int			i;

	size = 1;
	i = 1;
	if (n < 0)
	{
		size++;
		n = -n;
	}
	if (n == 0)
		return (1);
	while (n / i > 0)
	{
		size++;
		i *= 10;
	}
	size--;
	return (size);
}

int		check(char *s, t_room *t)
{
	while (t)
	{
		if (!ft_strcmp(s, t->name))
			return (1);
		t = t->next;
	}
	return (0);
}

int	length_connect(t_connect *t)
{
	t_connect *tmp;
	int	n;

	n = 0;
	tmp = t;
	if (!tmp)
		return (n);
	while (tmp)
	{
		n++;
		tmp = tmp->next;
	}
	return (n - 1);
}

void	length_arr_connect(t_connect_arr *arr)
{
	t_connect_arr *tmp;

	tmp = arr;
	while (tmp)
	{
		tmp->length = length_connect(tmp->s);
		tmp = tmp->next;
	}
}

void	printing_connect(t_lem_in t)
{
	t_room		*tmp;
	int 		i;
	int 		j;

	i = 0;
	j = 0;
	printf(" ");
	tmp = t.rooms;
	while (tmp)
	{
		printf(" %s ", tmp->name);
		tmp = tmp->next;
	}
	printf("\n");
	tmp = t.rooms;
	while (i < t.numb_rooms)
	{
		j = 0;
		printf("%s", tmp->name);
		tmp = tmp->next;
		while (j < t.numb_rooms)
		{
			printf(" %c ", t.con[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	print_connect(t_connect *t)
{
	t_connect *tmp;

	tmp = t;
	if (!tmp)
		printf("%s\n", "no path");
	while (tmp)
	{
		printf("%s\n", tmp->r);
		tmp = tmp->next;
	}
}

void	print_arr_connect(t_connect_arr *arr)
{
	t_connect_arr *tmp;

	tmp = arr;
	while (tmp)
	{
		print_connect(tmp->s);
		printf("length %d\n", tmp->length);
		tmp = tmp->next;
		printf("\n");
	}	
}
