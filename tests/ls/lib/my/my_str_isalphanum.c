/*
** EPITECH PROJECT, 2019
** my_str_isalpha
** File description:
** alpha
*/

int my_str_isalphanum(char c)
{
    if (48 <= c && c <= 57 || 65 <= c && c <= 90 || 65 <= c && c <= 90) {
        return (1);
    } else {
        return (0);
    }
}
