/*
** EPITECH PROJECT, 2020
** no args
** File description:
** normal ls
*/

#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include "../include/my.h"
#include <stdlib.h>
#include "../include/all.h"

void no_arg(void)
{
    DIR *dir;
    struct dirent *in;
    t_s_list *list = NULL;
    t_s_list *save = NULL;

    dir = opendir("./");
    in = readdir(dir);
    while (in != NULL) {
        if (list, in->d_name[0] != '.')
            list = fill_list_s(list, in->d_name);
        in = readdir(dir);
    }
    list = sort_list_s_alpha(list);
    display_list_s(list);
    closedir(dir);
}