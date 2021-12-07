/*
** EPITECH PROJECT, 2021
** B-PSU-400-RUN-4-1-malloc-paul.brancieq
** File description:
** linkedList
*/

#include "include/my_malloc.h"
#include <stdlib.h>

my_malloc_t *create_elem(void *ptr, int block_size, state_t state)
{
    my_malloc_t *elem = ptr;

    if (block_size < sizeof(my_malloc_t) || ptr == NULL)
        return NULL;
    elem->b_offset = block_size - sizeof(my_malloc_t);
    elem->memory = (void *)ptr + sizeof(my_malloc_t);
    elem->next = NULL;
    elem->prev = NULL;
    elem->state = state;
    return (elem);
}

int suppr_elem(my_malloc_t *list)
{
    if (list == NULL)
        return 1;
    if (list->prev != NULL)
    {
        list->prev->next = list->next;
    }
    if (list->next != NULL)
    {
        list->next->prev = list->prev;
    }
    return 0;
}

int insert_elem(my_malloc_t *new_elem, my_malloc_t *next)
{
    if (next == NULL)
        return (0);
    else if (new_elem == NULL)
        return 1;
    next->prev = new_elem;
    next->next = new_elem->next;
    if (next->next != NULL)
        next->next->prev = next;
    new_elem->next = next;
    return 0;
}

my_malloc_t *get_last(my_malloc_t *list)
{
    if (list == NULL)
        return NULL;
    while (list->next != NULL)
        list = list->next;
    return list;
}

my_malloc_t *add_elem_at_end(my_malloc_t *elem)
{
    my_malloc_t *end_list = get_last(memory_list);

    if (elem == NULL)
        return memory_list;
    if (end_list == NULL)
        return memory_list = elem;
    elem->prev = end_list;
    end_list->next = elem;
    return elem;
}