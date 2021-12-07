/*
** EPITECH PROJECT, 2021
** B-PSU-400-RUN-4-1-malloc-paul.brancieq
** File description:
** my_calloc
*/

#include "include/my_malloc.h"

void *calloc(size_t nmemb, size_t size)
{
    size_t total_size = nmemb * size;
    void *ret = malloc(total_size);
    char *tmp = ret;

    if (ret == NULL)
        return ret;
    for (int i = 0; i != nmemb; i++)
    {
        tmp[i] = 0;
    }
    return ret;
}