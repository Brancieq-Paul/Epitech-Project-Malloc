/*
** EPITECH PROJECT, 2021
** B-PSU-400-RUN-4-1-malloc-paul.brancieq
** File description:
** test_calloc
*/

#include <assert.h>
#include <unistd.h>
#include "../include/my_malloc.h"

int test_malloc_and_calloc(void)
{
    char *test = malloc(sizeof(int) * 2);

    test[0] = 1;
    test[1] = 2;
    free(test);
    test = malloc(sizeof(int) * 2);
    if (!(memory_list->state == USED)) {
        return 1;
    }
    if (!(test[0] == 1)) {
        return 1;
    }
    free(test);

    test = calloc(2, sizeof(int));
    if (!(memory_list->state == USED)) {
        return 1;
    }
    if (!(test[0] == 0)) {
        return 1;
    }
    free(test);
    return (0);
}