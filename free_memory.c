/*
** EPITECH PROJECT, 2021
** B-PSU-400-RUN-4-1-malloc-paul.brancieq
** File description:
** insert_new_block
*/

#include "include/my_malloc.h"
#include <unistd.h>
#include <stdio.h>

my_malloc_t *defrag(my_malloc_t *pos)
{
    if (pos->state == USED)
        return (NULL);
    while (pos->prev != NULL && pos->prev->state != USED)
        pos = pos->prev;
    while (pos->next != NULL && pos->next->state != USED) {
        if (pos->next->next != NULL)
            pos->b_offset += ((void *)pos->next->next - (void *)pos->next);
        else
            pos->b_offset += ((void *)sbrk(0) - (void *)pos->next);
        if (suppr_elem(pos->next))
            return NULL;
    }
    if (pos->next == NULL)
        pos->b_offset = sbrk(0) - (void *)pos - sizeof(my_malloc_t);
    else
        pos->b_offset = ((void *)pos->next - (void *)pos - sizeof(my_malloc_t));
    return (pos);
}

my_malloc_t *add_block(my_malloc_t *list, int block_size)
{
    my_malloc_t *ret;
    void *new_space = sbrk(block_size);
    my_malloc_t *new_head = create_elem(new_space, block_size, FREE);

    if (add_elem_at_end(new_head) == NULL)
    {
        write(2, "Error: try to add empty element to list", 40);
        return NULL;
    }
    ret = defrag(new_head);
    if (ret == NULL)
    {
        write(2, "Error: try to defrag in add block", 34);
        return NULL;
    }
    return (ret);
}

void free(void *pointer)
{
    my_malloc_t *to_free = NULL;

    if (pointer == NULL)
        return;
    to_free = pointer - sizeof(my_malloc_t);
    to_free->state = FREE;
    if (defrag(to_free) == NULL)
    {
        write(2, "Error: try to defrag in add block", 34);
        return;
    }
}