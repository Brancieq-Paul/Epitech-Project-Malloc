/*
** EPITECH PROJECT, 2019
** mu_putstr
** File description:
** put str
*/

#include <unistd.h>

void my_putchar(char c);

int my_putstr(char const *str)
{
    int i;

    i =  0;
    while (str[i] != '\0') {
        my_putchar(str[i]);
        i = i + 1;
    }
}
