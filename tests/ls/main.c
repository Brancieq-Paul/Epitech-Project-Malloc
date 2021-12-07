/*
** EPITECH PROJECT, 2020
** main
** File description:
** for ls
*/

#include "include/statis.h"
#include "include/my.h"
#include <stdio.h>
#include "include/all.h"
#include <stdlib.h>

char *add_opt(char *opt, char *add)
{
    int i = 1;

    while (add[i] != '\0')
    {
        opt = char_add(opt, add[i]);
        i += 1;
    }
    return (opt);
}

char *take_opt(char **av)
{
    int i = 0;
    char *opt = NULL;

    while (av[i] != NULL) {
        if (av[i][0] == '-') {
            opt = add_opt(opt, av[i]);
        }
        i += 1;
    }
    return (opt);
}

t_s_list *take_files(char **av, int ac)
{
    int i = 1;
    int u = 0;
    t_s_list *files = NULL;

    while (av[i] != NULL) {
        if (av[i][0] != '-') {
            files = fill_list_s(files, my_strdup(av[i]));
        }
        i += 1;
    }
    return (files);
}

int main(int ac, char **av)
{
    char *opt = NULL;
    t_s_list *files = NULL;

    opt = take_opt(av);
    files = take_files(av, ac);
    ls_all(opt, files);
    return (0);
}