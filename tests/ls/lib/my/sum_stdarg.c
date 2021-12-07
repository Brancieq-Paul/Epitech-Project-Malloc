/*
** EPITECH PROJECT, 2019
** sum_stdarg
** File description:
** sum for print f
*/

#include <stdarg.h>

#include "../include/my.h"

int sum_stdarg( int i, int nb , ... )
{
    int res = 0;
    va_list ap;
    int c = 0;
    int tmp = 0;

    va_start(ap, nb);
    if (i == 0) {
        while (c < nb) {
            tmp = va_arg(ap, int);
            c = c + 1;
            res = res + tmp;
            tmp = 0;
        }
    } else if (i == 1)
        while (c < nb) {
            tmp = my_strlen(va_arg(ap, char *));
            c = c + 1;
            res = res + tmp;
        }
    va_end(ap);
    return (res);
}