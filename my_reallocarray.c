/*
** EPITECH PROJECT, 2021
** B-PSU-400-RUN-4-1-malloc-paul.brancieq
** File description:
** my_reallocarray
*/

#include "include/my_malloc.h"
#include <stdint.h>

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
    if ((nmemb >= MAX || size >= MAX) &&
            nmemb > 0 && SIZE_MAX / nmemb < size) {
                return NULL;
    }
    return realloc(ptr, size * nmemb);
}