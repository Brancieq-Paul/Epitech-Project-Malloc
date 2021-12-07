/*
** EPITECH PROJECT, 2020
** display
** File description:
** display
*/


#include "../../include/statis.h"
#include "../../include/my.h"
#include <stdio.h>
#include "../../include/all.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <sys/sysmacros.h>
#include <pwd.h>
#include <grp.h>

void display_list_s(t_s_list *list)
{
    while (list != NULL) {
        my_putstr(list->string);
        list = list->next;
        if (list != NULL)
            my_putstr("  ");
        else
            my_putchar('\n');
    }
}

void display_type(statis_t sstatis)
{
    if (verify_type(sstatis) == 1)
        my_putchar('b');
    if (verify_type(sstatis) == 2)
        my_putchar('c');
    if (verify_type(sstatis) == 3)
        my_putchar('d');
    if (verify_type(sstatis) == 4)
        my_putchar('p');
    if (verify_type(sstatis) == 5)
        my_putchar('l');
    if (verify_type(sstatis) == 6)
        my_putchar('-');
    if (verify_type(sstatis) == 7)
        my_putchar('s');
}

void putspace(int nbr, int ref)
{
    while (nbr < ref) {
        my_putchar(' ');
        ref = ref / 10;
    }
}

void display_line(statis_t sstatis, char *name)
{
    display_type(sstatis);
    my_putstr(sstatis.perm);
    my_putchar(' ');
    my_put_nbr(sstatis.hard_link_nbr);
    my_putchar(' ');
    my_putstr(getpwuid(sstatis.UID)->pw_name);
    my_putchar(' ');
    my_putstr(getgrgid(sstatis.GID)->gr_name);
    my_putchar(' ');
    putspace(sstatis.filesize, 10000);
    my_put_nbr(sstatis.filesize);
    my_putchar(' ');
    my_putstr(sstatis.date);
    my_putchar(' ');
    my_putstr(name);
}

void display_list_l(t_s_list *list, t_s_list *path, char *opt)
{
    statis_t sstatis;
    DIR *dir = NULL;
    int ind = 0;
    char *path_name = NULL;

    struct dirent *in = NULL;
    dir = open_dir(path);
    in = readdir(dir);
    while (in != NULL || (in != NULL && ind == 0)) {
        path = init_path(path, in->d_name);
        path_name = create_str_from_list(path);
        path = back_path(path);
        sstatis = statis(path_name);
        if (in->d_name[0] != '.' || verifs_opt(opt, 'a')) {
            display_line(sstatis, in->d_name);
            my_putchar('\n');
        }
        in = readdir(dir);
        ind = 1;
    }
}