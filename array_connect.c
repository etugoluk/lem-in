#include "lem_in.h"

t_connect_arr	*create_con_arr(t_connect *t)
{
	t_connect_arr	*arr;
	if (!t)
		return (NULL);
	arr = (t_connect_arr *)malloc(sizeof(t_connect_arr));
	arr->s = (t_connect *)malloc(sizeof(t_connect));
	arr->next = NULL;
	arr->s = t;
	arr->length = length_connect(t);
	return (arr);
}

int    array_of_path(t_lem_in 	t)
{
    t_connect_arr	*arr;

    arr = NULL;
    int s = find_start_num_room(t);
    int f = find_finish_num_room(t);
    if (!(arr = create_con_arr(connects(s, f, t, arr))))
    	return (0);
    t_connect *tmp_con;
    t_connect_arr	*arr1;
    arr1 = arr;
    while ((tmp_con = connects(s, f, t, arr)))
    {
        arr1->next = create_con_arr(tmp_con);
        arr1 = arr1->next;
    }
    length_arr_connect(arr);
   // print_arr_connect(arr);
    sort_connects(arr);
//    printf("SORTING\n");
   //print_arr_connect(arr);
    cross(t, arr);
    //cross_array(arr, t);
    //print_numb_ants(t.rooms);
    return (1);
}
