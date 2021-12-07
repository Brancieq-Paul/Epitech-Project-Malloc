/*
** EPITECH PROJECT, 2020
** sort aplpha
** File description:
** sort
*/

#include "../../include/statis.h"
#include "../../include/my.h"
#include <stdio.h>
#include "../../include/all.h"
#include <stdlib.h>

int compare(t_s_list *list)
{
    int i = 0;
    char *actual = list->string;
    char *next = list->next->string;

    while (1)
    {
        if ((actual[i] == '\0' && next[i] == '\0') || actual[i] == '\0')
            return (0);
        else if (next[i] == '\0')
            return (1);
        if (actual[i] < next [i])
            return (0);
        if (actual[i] > next [i])
            return (1);
        i += 1;
    }
}

int verifs(t_s_list *list)
{
    while (list->next != NULL) {
        if (compare(list) == 1)
            return (1);
        list = list->next;
    }
    return (0);
}

t_s_list *sort_list_s_alpha(t_s_list *list)
{
    t_s_list *save = list;
    t_s_list *save2 = NULL;

    while (save->next != NULL) {
        if (compare(save) == 1 && save2 == NULL && save->next) {
            save2 = save->next;
            save->next = save2->next;
            save2->next = save;
            list = save2;
        } else if (compare(save) == 1) {
            save2->next = save->next;
            save->next = save->next->next;
            save2->next->next = save;
            save2 = save2->next;
        } else {
            save2 = save;
            save = save->next;
        }
    }
    if (verifs(list) == 1)
            list = sort_list_s_alpha(list);
    return (list);
}