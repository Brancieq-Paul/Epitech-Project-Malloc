/*
** EPITECH PROJECT, 2021
** B-PSU-400-RUN-4-1-malloc-paul.brancieq
** File description:
** my_realloc
*/

#include "include/my_malloc.h"

void *new_alloc(void *ptr, size_t old_size, size_t size)
{
    char *new;
    char *old = ptr;

    free(ptr);
    new = malloc(size);
    if (new == NULL) {
        return (NULL);
    }
    for (int i = 0; i != size; i++) {
        if (i < old_size)
            new[i] = old[i];
    }
    return new;
}

void *realloc(void *ptr, size_t size)
{
    my_malloc_t *to_rea = NULL;
    size_t total_size;

    if (ptr == NULL)
        return malloc(size);
    to_rea = ptr - sizeof(my_malloc_t);
    if ((to_rea->next != NULL && to_rea->next->state == FREE &&
    to_rea->b_offset + sizeof(my_malloc_t) >= size) ||
    (size <= to_rea->b_offset)) {
        free(ptr);
        to_rea = use_space(size, to_rea);
        return to_rea->memory;
    } else {
        ptr = new_alloc(ptr, to_rea->b_offset, size);
        return (ptr);
    }
}