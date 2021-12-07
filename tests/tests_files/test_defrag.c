/*
** EPITECH PROJECT, 2021
** B-PSU-400-RUN-4-1-malloc-paul.brancieq
** File description:
** defrag
*/

#include <assert.h>
#include <unistd.h>
#include "../include/my_malloc.h"

int test_defrag(void)
{
    char *test = malloc(sizeof(char) * 2);
    char *test2 = malloc(sizeof(char) * 300);
    char *test3 = malloc(sizeof(char) * 400);
    char *test4 = malloc(sizeof(char) * 500);

    if (!(memory_list->b_offset == 2))
        return 1;
    if (!(memory_list->state == USED))
        return 1;
    if (!(memory_list->next->b_offset == 300))
        return 1;
    if (!(memory_list->next->state == USED))
        return 1;
    if (!(memory_list->next->next->b_offset == 400))
        return 1;
    if (!(memory_list->next->next->state == USED))
        return 1;
    test[0] = 'a';
    test[1] = '\0';
    if (!(test[0] == 'a' && test[1] == '\0'))
        return 1;
    free(test2);
    free(test3);
    if (!(memory_list->next->b_offset == 732))
        return 1;
    free(test);
    free(test4);
    if (!(memory_list->b_offset == (getpagesize() * 2) - sizeof(my_malloc_t)))
        return 1;
    return (0);
}