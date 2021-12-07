/*
** EPITECH PROJECT, 2021
** B-PSU-400-RUN-4-1-malloc-paul.brancieq
** File description:
** my_malloc
*/

#pragma once

#include <unistd.h>

#define MAX (1UL << (sizeof(size_t) * 4))

typedef long unsigned int size_t;

typedef enum state_s
{
    USED,
    FREE
} state_t;

typedef struct my_malloc_s
{
    void *memory;
    int b_offset;
    state_t state;
    struct my_malloc_s *next;
    struct my_malloc_s *prev;
} my_malloc_t;

my_malloc_t *create_elem(void *ptr, int block_size, state_t state);

int insert_elem(my_malloc_t *new_elem, my_malloc_t *next);

int suppr_elem(my_malloc_t *list);

my_malloc_t *get_last(my_malloc_t *list);

my_malloc_t *add_elem_at_end(my_malloc_t *elem);

my_malloc_t *add_block(my_malloc_t *list, int block_size);

void *use_space(size_t memorySize, my_malloc_t *space);

void *malloc(size_t memorySize);

void free(void *pointer);

void *calloc(size_t nmemb, size_t size);

void *realloc(void *ptr, size_t size);

void *reallocarray(void *ptr , size_t  nmemb , size_t  size);

extern my_malloc_t *memory_list;