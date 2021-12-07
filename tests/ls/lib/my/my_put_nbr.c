/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** put nbr
*/

#include <stdio.h>

void my_putchar(char c);

int my_put_nbr(int nb)
{
    int rnbc;
    int nbc = 1;
    int ch;
    int mod;

    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
    }
    rnbc = nb;
    while (rnbc >= 10) {
        rnbc = rnbc / 10;
        nbc = nbc * 10;
    }
    while (nbc != 0) {
        ch = (nb / nbc);
        ch = ch % 10;
        nbc = nbc / 10;
        my_putchar(ch + 48);
    }
}
