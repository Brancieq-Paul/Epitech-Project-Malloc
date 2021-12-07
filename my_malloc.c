/*
** EPITECH PROJECT, 2021
** B-PSU-400-RUN-4-1-malloc-paul.brancieq
** File description:
** my_malloc
*/

#include "include/my_malloc.h"
#include <unistd.h>

my_malloc_t *memory_list = NULL;

my_malloc_t *search_for_space(size_t memorySize)
{
    my_malloc_t *tmp = memory_list;
    my_malloc_t *res = NULL;

    if (memory_list == NULL)
        return (NULL);
    else
    {
        while (tmp != NULL)
        {
            if (tmp->state == FREE && ((tmp->b_offset >=
            memorySize && res == NULL) || (res != NULL && tmp->b_offset
            >= memorySize && tmp->b_offset < res->b_offset))) {
                res = tmp;
            }
            tmp = tmp->next;
        }
        return res;
    }
}

void *use_space(size_t memorySize, my_malloc_t *space)
{
    int oc_rest = space->b_offset - memorySize;
    my_malloc_t *rest = create_elem((void *)space + sizeof(my_malloc_t)
    + memorySize, oc_rest, FREE);

    space->b_offset = memorySize;
    space->state = USED;
    if (rest == NULL) {
        space->b_offset += oc_rest;
    } else if (insert_elem(space, rest))
    {
        write(2, "Error: in insert", 17);
        return (NULL);
    }
    return (space);
}

void *malloc(size_t memorySize)
{
    my_malloc_t *ret;

    if (memorySize == 0)
        return (NULL);
    int bloc_needed_new = (int)(memorySize /(getpagesize() * 2) + 1)
    * (getpagesize() * 2);
    my_malloc_t *free_space = search_for_space(memorySize);

    if (free_space == NULL)
        free_space = add_block(memory_list, bloc_needed_new);
    ret = use_space(memorySize, free_space);
    return (ret->memory);
}