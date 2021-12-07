/*
** EPITECH PROJECT, 2020
** display and recu
** File description:
** display and launch recu
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

int display(t_s_list *list, char *opt, t_s_list *path)
{
    list = sort_choice(list, opt);
    if (verifs_opt(opt, 'l') == 0)
        display_list_s(list);
    if (verifs_opt(opt, ('l')))
        display_list_l(list, path, opt);
    return (0);
}

int verify_type(statis_t sstatis)
{
    int m = sstatis.mode & S_IFMT;
    if (m == S_IFBLK)
        return (1);
    if (m == S_IFCHR)
        return (2);
    if (m == S_IFDIR)
        return (3);
    if (m == S_IFIFO)
        return (4);
    if (m == S_IFLNK)
        return (5);
    if (m == S_IFREG)
        return (6);
    if (m == S_IFSOCK)
        return (7);
    return (0);
}

int recursive(char *opt, t_s_list *path, int indic)
{
    statis_t sstatis;
    char *path_name = NULL;
    DIR *dir;
    int ind = 0;

    struct dirent *in = NULL;
    dir = open_dir(path);
    in = readdir(dir);
    while (in != NULL || (in != NULL && ind == 0)) {
        path = init_path(path, in->d_name);
        path_name = create_str_from_list(path);
        path = back_path(path);
        sstatis = statis(path_name);
        if (verify_type(sstatis) == 3 && verifs_opt(opt, 'R') == 1 &&
        in->d_name[0] != '.')
            ls(opt, my_strdup(in->d_name), path, indic);
        ind = 1;
        in = readdir(dir);
    }
    closedir(dir);
    return (0);
}
