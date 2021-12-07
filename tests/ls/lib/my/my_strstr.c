/*
** EPITECH PROJECT, 2019
** my_strstr
** File description:
** my_strsstr
*/

int my_strlen(char const *str);

char my_putstr(char *str);

int verify_pattern(char *str, char const *to_find)
{
    int u = 0;
    int t = my_strlen(to_find) - 1;

    while (to_find[u] != '\0') {
        if (str[u] != to_find[u])
            return (0);
        u = u + 1;
    }
    return (1);
}

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;
    int u;

    while (str[0] != '\0') {
        str = str + 1;
        if (str[0] == to_find[0])
            u = verify_pattern(str, to_find);
        i = i + 1;
        if (u == 1)
            return (str);
    }
    return (0);
}
