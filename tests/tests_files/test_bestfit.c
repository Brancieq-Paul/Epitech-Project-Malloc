/*
** EPITECH PROJECT, 2021
** B-PSU-400-RUN-4-1-malloc-paul.brancieq
** File description:
** test_bestfit
*/

#include <assert.h>
#include <unistd.h>
#include "../include/my_malloc.h"

int test_bestfit(void)
{
    char *test = malloc(sizeof(char) * 2);
    char *test2 = malloc(sizeof(char) * 44);
    char *test3 = malloc(sizeof(char) * 1);

    if (!(memory_list->b_offset == 2))
        return 1;
    if (!(memory_list->next->b_offset == 44))
        return 1;
    if (!(memory_list->next->next->b_offset == 1))
        return 1;
    free(test2);
    test2 = malloc(sizeof(char) * 44);
    if (!(memory_list->b_offset == 2))
        return 1;
    if (!(memory_list->next->b_offset == 44))
        return 1;
    if (!(memory_list->next->next->b_offset == 1))
        return 1;
    free(test2);
    test2 = malloc(sizeof(char) * 45);
    if (!(memory_list->b_offset == 2))
        return 1;
    if (!(memory_list->next->b_offset == 44))
        return 1;
    if (!(memory_list->next->state == FREE))
        return 1;
    if (!(memory_list->next->next->b_offset == 1))
        return 1;
    if (!(memory_list->next->next->next->b_offset == 45))
        return 1;
    free(test);
    free(test2);
    free(test3);
    if (!(memory_list->b_offset == (getpagesize() * 2) - sizeof(my_malloc_t)))
        return 1;
    return (0);
}