/*
** EPITECH PROJECT, 2020
** path
** File description:
** path
*/

#include "../include/statis.h"
#include "../include/my.h"
#include <stdio.h>
#include "../include/all.h"
#include <stdlib.h>

t_s_list *back_path(t_s_list *path)
{
    if (path->next == NULL)
    {
        free(path->string);
        path = NULL;
    } else {
        while (path->next->next != NULL)
            path = path->next;
        free(path->next->string);
        path->next->string = NULL;
        path->next = NULL;
    }
    return (path);
}

t_s_list *init_path(t_s_list *path, char *name)
{
    t_s_list *save = path;

    if (path == NULL) {
        path = malloc(sizeof(t_s_list));
        path->string = name;
        path->next = NULL;
        save = path;
    } else {
        while (path->next != NULL)
            path = path->next;
        path->next = malloc(sizeof(t_s_list));
        path->next->string = my_strdup(name);
        path->next->next = NULL;
    }
    return (save);
}