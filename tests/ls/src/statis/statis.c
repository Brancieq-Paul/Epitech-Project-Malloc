/*
** EPITECH PROJECT, 2020
** statis
** File description:
** all metadatas
*/

#include "../../include/statis.h"
#include "../../include/my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <time.h>

char *perm2(statis_t sstatis, char *perm)
{
    if (sstatis.mode & S_IWGRP)
        perm[4] = 'w';
    if (sstatis.mode & S_IXGRP)
        perm[5] = 'x';
    if (sstatis.mode & S_IROTH)
        perm[6] = 'r';
    if (sstatis.mode & S_IWOTH)
        perm[7] = 'w';
    if (sstatis.mode & S_IXOTH)
        perm[8] = 'x';
    return (perm);
}

char *perm(statis_t sstatis)
{
    char *perm = malloc(sizeof(char) * 10);
    int i = 0;

    while (i != 9) {
        perm[i] = '-';
        i += 1;
    }
    perm[9] = '\0';
    if (sstatis.mode & S_IRUSR)
        perm[0] = 'r';
    if (sstatis.mode & S_IWUSR)
        perm[1] = 'w';
    if (sstatis.mode & S_IXUSR)
        perm[1] = 'x';
    if (sstatis.mode & S_IRGRP)
        perm[3] = 'r';
    perm = perm2(sstatis, perm);
    return (perm);
}

char *convert_date(char *date)
{
    int i = 4;
    char *ret = malloc(sizeof(char) * 16);

    while (i != 16) {
        ret[i - 4] = date[i];
        i += 1;
    }
    ret[12] = '\0';
    return (ret);
}

statis_t statis(char *pathname)
{
    statis_t statis;
    struct stat *stats = malloc(sizeof(struct stat));

    lstat(pathname, stats);
    statis.filesize = stats->st_size;
    statis.allocated_space = stats->st_blocks;
    statis.UID = stats->st_uid;
    statis.GID = stats->st_gid;
    statis.hard_link_nbr = stats->st_nlink;
    statis.inode = stats->st_ino;
    statis.mode = stats->st_mode;
    statis.date = ctime(&stats->st_mtime);
    statis.date = convert_date(statis.date);
    statis.perm = perm(statis);
    return (statis);
}