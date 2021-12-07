/*
** EPITECH PROJECT, 2020
** ls_all
** File description:
** ls
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

DIR *open_dir(t_s_list *path)
{
    char *buff = NULL;
    int i = 0;
    DIR *dir = NULL;

    while (path != NULL) {
        while (path->string[i] != '\0') {
            buff = char_add(buff, path->string[i]);
            i += 1;
        }
        if (path->next != NULL && path->string[my_strlen(path->string) - 1] !=
        '/')
            buff = char_add(buff, '/');
        i = 0;
        path = path->next;
    }
    buff = char_add(buff, '\0');
    dir = opendir(buff);
    return (dir);
}

int display_path(t_s_list *path, int indic, char *opt)
{
    while ((path != NULL && indic == 1) || (path != NULL && verifs_opt(opt,
    'R') == 1)) {
        my_putstr(path->string);
        if (path->next != NULL)
            my_putchar('/');
        path = path->next;
    }
    if (indic == 1 || verifs_opt(opt, 'R'))
        my_putstr(":\n");
    return (1);
}

int ls(char *opt, char *name, t_s_list *path, int indic)
{
    DIR *dir = NULL;
    struct dirent *in = NULL;
    t_s_list *list = NULL;
    statis_t sstatis;

    if (indic != 0)
        my_putchar('\n');
    path = init_path(path, name);
    dir = open_dir(path);
    in = readdir(dir);
    indic = display_path(path, indic, opt);
    while (in != NULL) {
        if (in->d_name[0] != '.' || verifs_opt(opt, 'a') == 1)
            list = fill_list_s(list, in->d_name);
        in = readdir(dir);
    }
    if (list != NULL) {
        display(list, opt, path);
        recursive(opt, path, indic);
    }
    closedir(dir);
    path = back_path(path);
    return (0);
}

int ls_all(char *opt, t_s_list *files)
{
    t_s_list *path = NULL;
    int indic = 0;

    if (files != NULL && files->next != NULL)
        indic = 1;
    else if (files == NULL) {
        files = malloc(sizeof(t_s_list));
        files->next = NULL;
        files->string = my_strdup(".");
    }
    while (files != NULL) {
        ls(opt, files->string, path, indic);
        files = files->next;
        if (files != NULL)
            my_putchar('\n');
    }
    return (0);
}