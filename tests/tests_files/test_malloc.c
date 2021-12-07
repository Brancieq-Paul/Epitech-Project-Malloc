/*
** EPITECH PROJECT, 2021
** B-PSU-400-RUN-4-1-malloc-paul.brancieq
** File description:
** test_malloc
*/

#include <assert.h>
#include <unistd.h>
#include "../include/my_malloc.h"

int test_first_string(void)
{
    char *test = malloc(sizeof(char) * 2);

    if (!(memory_list->b_offset == 2))
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

int test_succed_alloc(void)
{
    char *test = malloc(sizeof(char) * 2);

    if (!(memory_list->b_offset == 2))
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
    test = malloc(sizeof(char) * 2);
    if (!(memory_list->b_offset == 2))
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

int test_multi_alloc(void)
{
    char *test = malloc(sizeof(char) * 2);
    char *test2 = malloc(sizeof(char) * 10);

    if (!(memory_list->b_offset == 2))
        return 1;
    if (!(memory_list->next->b_offset == 10))
        return 1;
    if (!(memory_list->state == USED))
        return 1;
    if (!(memory_list->next->state == USED))
        return 1;
    int test3 = !(memory_list->next->next->state == FREE);
    if (test3) {
        return 1;
    }
    if (!((void *)memory_list->next - (void *)memory_list == sizeof(my_malloc_t) + sizeof(char) * 2)) {
        return 1;
    }
    test2[0] = 'a';
    test2[1] = '\0';
    test[0] = 'b';
    test[1] = '\0';
    if (!(test2[0] == 'a' && test2[1] == '\0'))
        return 1;
    if (!(test[0] == 'b' && test[1] == '\0'))
        return 1;
    free(test);
    free(test2);
    if (!(memory_list->b_offset == (getpagesize() * 2) - sizeof(my_malloc_t)))
        return 1;
    return (0);
}

int test_big_alloc_one_block(void)
{
    char *test = malloc(sizeof(char) * 8159);

    if (!(memory_list->b_offset == 8160))
        return 1;
    if (!(memory_list->state == USED))
        return 1;
    free(test);
    if (!(memory_list->b_offset == (getpagesize() * 2) - sizeof(my_malloc_t)))
        return 1;
    return (0);
}

int test_malloc_and_free_NULL(void)
{
    char *test1 = NULL;
    char *test2 = malloc(0);

    if (!(test2 == NULL))
        return 1;
    if (!(memory_list->b_offset == (getpagesize() * 2) - sizeof(my_malloc_t)))
        return 1;
    free(test1);
    free(test2);
    if (!(memory_list->b_offset == (getpagesize() * 2) - sizeof(my_malloc_t)))
        return 1;
    return 0;
}