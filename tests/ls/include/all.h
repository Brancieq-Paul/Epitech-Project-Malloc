/*
** EPITECH PROJECT, 2020
** all
** File description:
** all include
*/

#include <dirent.h>
#include "statis.h"

#ifndef ALL_

#define ALL_

typedef struct s_list
{
    char *string;
    struct s_list *next;
} t_s_list;

t_s_list *fill_list_s(t_s_list *list, char *string);

void display_list_s(t_s_list *list);

t_s_list *back_path(t_s_list *path);

t_s_list *init_path(t_s_list *path, char *name);

t_s_list *sort_list_s_alpha(t_s_list *list);

char *char_add(char *str, char add);

t_s_list *sort_choice(t_s_list *list, char *opt);

int verifs_opt(char *opt, char c);

int ls_all(char *opt, t_s_list *files);

char *tabpath_to_string(t_s_list *path);

int display(t_s_list *list, char *opt, t_s_list *path);

char *create_str_from_list(t_s_list *list);

int ls(char *opt, char *name, t_s_list *path, int indic);

int recursive(char *opt, t_s_list *path, int indic);

DIR *open_dir(t_s_list *path);

int verify_type(statis_t sstatis);

void display_list_l(t_s_list *list, t_s_list *path, char *opt);

void no_arg(void);

#endif