/*
** EPITECH PROJECT, 2020
** create list
** File description:
** list
*/

#include "../../include/statis.h"
#include "../../include/my.h"
#include <stdio.h>
#include "../../include/all.h"
#include <stdlib.h>

t_s_list *fill_list_s(t_s_list *list, char *string)
{
    t_s_list *save = NULL;

    if (list == NULL) {
        list = malloc(sizeof(t_s_list));
        list->string = string;
        list->next = NULL;
        save = list;
    } else {
        save = list;
        while (list->next != NULL)
            list = list->next;
        list->next = malloc(sizeof(t_s_list));
        list->next->string = string;
        list->next->next = NULL;
    }
    return (save);
}