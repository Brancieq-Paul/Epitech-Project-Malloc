/*
** EPITECH PROJECT, 2020
** sort choics
** File description:
** sort
*/

#include "../../include/statis.h"
#include "../../include/my.h"
#include <stdio.h>
#include "../../include/all.h"
#include <stdlib.h>

t_s_list *sort_choice(t_s_list *list, char *opt)
{
    if (verifs_opt(opt, 't') == 0 && verifs_opt(opt, 'r') == 0)
        list = sort_list_s_alpha(list);
    return (list);
}