/*
** EPITECH PROJECT, 2019
** my_isneg
** File description:
** isneg
*/

#include <unistd.h>

void my_putchar(char c);

int my_isneg(int n)
{
    if (n < 0)
    {
        my_putchar('N');
    }
    else if (n >= 0)
    {
        my_putchar('P');
    }
}
