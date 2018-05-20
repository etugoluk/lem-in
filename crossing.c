#include "lem_in.h"
#include <stdio.h>

int ft_length(t_connect *con)
{
    t_connect *tmp_con = con;
    int i = 0;

    while (tmp_con)
    {
        i++;
        tmp_con = tmp_con->next;
    }
    return (i);
}

char *find_room(t_lem_in    t, t_connect_arr *arr, t_ant *ant)
{
    t_connect_arr *arr_tmp = arr;
    t_connect *tmp_con;
    int check = t.numb_rooms;

    while (arr_tmp)
    {
        tmp_con = arr_tmp->s;
        while (tmp_con)
        {
            if ((find_number_room(tmp_con->r, t.rooms) == ant->room))
            {
                if ((tmp_con->next) && (find_name(t.rooms, tmp_con->next->r)->num_ants == 0 || 
                    find_name(t.rooms, tmp_con->next->r)->finish == 1))
                {
                    if (ft_length(tmp_con->next) > check + 1)
                        return (find_name_room(ant->room, t.rooms));
                    else
                        return (tmp_con->next->r);
                }
                else if ((tmp_con->next) && (find_name(t.rooms, tmp_con->next->r)->num_ants))
                    check = ft_length(tmp_con->next);
                else
                    break;
            }
            tmp_con = tmp_con->next;
        }
        arr_tmp = arr_tmp->next;
    }
    return (find_name_room(ant->room, t.rooms));
}

void cross(t_lem_in l, t_connect_arr *arr)
{
    char *tmp_room;
    t_ant *tmp_ant = l.ants;
    t_room *r = find_number(l.rooms, find_finish_num_room(l));
    while (r->num_ants != l.sum_ants)
    {
        while (tmp_ant)
        {
            if (tmp_ant->room == find_finish_num_room(l))
            {
                tmp_ant = tmp_ant->next;
                continue;
            }
            tmp_room = find_room(l, arr, tmp_ant);
            find_name(l.rooms, find_name_room(tmp_ant->room, l.rooms))->num_ants--;
            if (ft_strcmp(tmp_room,find_name_room(tmp_ant->room, l.rooms)))
                printf("L%d-%s ", tmp_ant->number + 1, tmp_room);
            tmp_ant->room = find_number_room(tmp_room, l.rooms);
            find_name(l.rooms, find_name_room(tmp_ant->room, l.rooms))->num_ants++;
            tmp_ant = tmp_ant->next;
        }
        printf("\n");
        tmp_ant = l.ants;
    }
}
