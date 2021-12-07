/*
** EPITECH PROJECT, 2019
** my_revstr
** File description:
** rev_str
*/

char *my_revstr(char *str)
{
    int i;
    int u;
    int e;

    i = 0;
    while (str[i] != '\0') {
        i = i + 1;
    }
    i = i - 1;
    u = 0;
    while (i > u) {
        e = str[u];
        str[u] = str[i];
        str[i] = e;
        i = i - 1;
        u = u + 1;
    }
    return (str);
}
