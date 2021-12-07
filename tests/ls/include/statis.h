/*
** EPITECH PROJECT, 2020
** statis
** File description:
** struct and function for metadata
*/

#ifndef STATIS_

#define STATIS_

typedef struct statis_s
{
    char *filename;
    int mode;
    int inode;
    int hard_link_nbr;
    int allocated_space;
    int filesize;
    int UID;
    int GID;
    char *perm;
    char *date;
} statis_t;

statis_t statis(char *pathname);

#endif