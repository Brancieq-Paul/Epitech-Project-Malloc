/*
** EPITECH PROJECT, 2020
** charadd
** File description:
** charadd
*/

#include "../include/statis.h"
#include <sys/types.h>
#include "../include/my.h"
#include <stdio.h>
#include "../include/all.h"
#include <stdlib.h>
#include <dirent.h>
#include <sys/sysmacros.h>
#include <sys/stat.h>
#include <time.h>

char *char_add(char *str, char add)
{
    int i = 0;
    char *ret = NULL;

    if (str == NULL) {
        str = malloc(sizeof(char) * 1);
        str[0] = '\0';
    }
    ret = malloc(sizeof(char) * (my_strlen(str) + 2));
    while (str[i] != '\0') {
        ret[i] = str[i];
        i = i + 1;
    }
    ret[i] = add;
    ret[i + 1] = '\0';
    str = NULL;
    free(str);
    return (ret);
}

char *create_str_from_list(t_s_list *list)
{
    char *str = NULL;
    int i = 0;

    while (list != NULL) {
        while (list->string[i] != '\0') {
            str = char_add(str, list->string[i]);
            i += 1;
        }
        if (list->next != NULL && list->string[my_strlen(list->string) - 1] !=
        '/')
            str = char_add(str, '/');
        i = 0;
        list = list->next;
    }
    return (str);
}