/*
** EPITECH PROJECT, 2021
** B-PSU-400-RUN-4-1-my_malloc-paul.brancieq
** File description:
** tests
*/

#include <assert.h>
#include <unistd.h>
#include "include/my_malloc.h"

int test_first_string(void);

int test_succed_alloc(void);

int test_multi_alloc(void);

int test_big_alloc_one_block(void);

int test_malloc_and_free_NULL(void);

int test_malloc_and_calloc(void);

int test_simple_alloc_with_realloc(void);

int test_defrag(void);

int test_simple_realloc(void);

int test_bestfit(void);

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        my_putchar(str[i]);
        i = i + 1;
    }
}

int main(void)
{
    if (test_first_string()) {
        my_putstr("Error in fist test\n");
        return 84;
    }
    if (test_succed_alloc()) {
        my_putstr("Error second test  (successive allocs)\n");
        return 84;
    }
    if (test_multi_alloc()) {
        my_putstr("Error third test  (multi allocs)\n");
        return 84;
    }
    if (test_big_alloc_one_block()) {
        my_putstr("Error fourth test  (big alloc)\n");
        return 84;
    }
    if (test_big_alloc_one_block()) {
        my_putstr("Error fifth test  (test NULL)\n");
        return 84;
    }
    if (test_malloc_and_calloc()) {
        my_putstr("Error sixth test  (test calloc comp malloc)\n");
        return 84;
    }
    if (test_malloc_and_free_NULL()) {
        my_putstr("Error sixth bis test  (test malloc and free NULL)\n");
        return 84;
    }
    if (test_simple_alloc_with_realloc()) {
        my_putstr("Error seven test  (test malloc with realloc)\n");
        return 84;
    }
    if (test_defrag()) {
        my_putstr("Error 8 test  (test defrag)\n");
        return 84;
    }
    if (test_simple_realloc()) {
        my_putstr("Error 9 test  (test realloc)\n");
        return 84;
    }
    if (test_bestfit()) {
        my_putstr("Error 10 test  (test bestfit)\n");
        return 84;
    }
    return 0;
}