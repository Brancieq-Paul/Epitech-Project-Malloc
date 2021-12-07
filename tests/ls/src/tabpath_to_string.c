/*
** EPITECH PROJECT, 2020
** tab to sring
** File description:
** tab to
*/

#include "../include/statis.h"
#include "../include/my.h"
#include <stdio.h>
#include "../include/all.h"
#include <stdlib.h>
#include <dirent.h>

char *tabpath_to_string(t_s_list *path)
{
    int i = 0;
    char *buff = NULL;

    while (path != NULL) {
        while (path->string[i] != '\0') {
            buff = char_add(buff, path->string[i]);
            i += 1;
        }
        if (path->next != NULL)
            buff = char_add(buff, '/');
        i = 0;
        path = path->next;
    }
    return (buff);
}
