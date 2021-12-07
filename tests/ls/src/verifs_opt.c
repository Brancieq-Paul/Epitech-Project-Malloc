/*
** EPITECH PROJECT, 2020
** verifs opt
** File description:
** opt
*/

#include "../include/statis.h"
#include "../include/my.h"
#include <stdio.h>
#include "../include/all.h"
#include <stdlib.h>
#include <dirent.h>

int verifs_opt(char *opt, char c)
{
    int i = 0;

    while (opt != NULL && opt[i] != '\0') {
        if (opt[i] == c)
            return (1);
        i = i + 1;
    }
    return (0);
}