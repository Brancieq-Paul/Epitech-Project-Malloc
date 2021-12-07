/*
** EPITECH PROJECT, 2019
** my_getnbr
** File description:
** getnbr
*/

#include <stdio.h>

int my_strlen(char const *str);

int my_compute_power_rec(int nb, int p);

void my_putchar(char c);

int calcul_nbr(char *str)
{
    int nb_char;
    int p_dix;
    int i = 0;
    int nb = 0;

    nb_char = my_strlen(str);
    p_dix = my_compute_power_rec(10, nb_char - 1);
    while (str[i] != '\0') {
        nb = nb + ((str[i] - 48) * p_dix);
        p_dix = p_dix / 10;
        i = i + 1;
    }
    return (nb);
}

int my_getnbr(char *str)
{
    int nb = 0;
    int neg = 0;

    if (str[0] == '-') {
        neg = 1;
        str = str + 1;
    }
    nb = calcul_nbr(str);
    if (neg == 1) {
        nb = nb * (-1);
    }
    return (nb);
}
