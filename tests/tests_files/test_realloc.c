/*
** EPITECH PROJECT, 2021
** B-PSU-400-RUN-4-1-malloc-paul.brancieq
** File description:
** test_realloc
*/

#include <assert.h>
#include <unistd.h>
#include "../include/my_malloc.h"

int test_simple_alloc_with_realloc(void)
{
    char *test = NULL;
    test = reallocarray(test, 2, 1);

    if (!(memory_list->b_offset == 2))
        return 1;
    if (!(memory_list->next->b_offset == (getpagesize() * 2) -
    sizeof(my_malloc_t) * 2 - memory_list->b_offset))
        return 1;
    if (!(memory_list->state == USED))
        return 1;
    test[0] = 'a';
    test[1] = '\0';
    if (!(test[0] == 'a' && test[1] == '\0'))
        return 1;
    free(test);
    if (!(memory_list->b_offset == (getpagesize() * 2) - sizeof(my_malloc_t)))
        return 1;
    return (0);
}

int test_simple_realloc(void)
{
    char *test = NULL;
    char *test2 = NULL;
    char *test3 = NULL;

    test = reallocarray(test, 2, 1);
    test2 = reallocarray(test2, 10, 1);
    test3 = reallocarray(test3, 1, 1);

    free(test2);
    test[0] = 'a';
    test = reallocarray(test, 8, 1);
    if (!(memory_list->b_offset == 8))
        return 1;
    if (!(memory_list->next->b_offset == 4))
        return 1;
    test = reallocarray(test, 8, 1);
    if (!(memory_list->b_offset == 8))
        return 1;
    if (!(memory_list->next->b_offset == 4))
        return 1;
    test = reallocarray(test, 300, 1);
    if (!(memory_list->state == FREE))
        return 1;
    if (!(memory_list->next->next->b_offset == 300))
        return 1;

    free(test);
    free(test3);
    if (!(memory_list->b_offset == (getpagesize() * 2) - sizeof(my_malloc_t)))
        return 1;
    return (0);
}