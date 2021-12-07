/*
** EPITECH PROJECT, 2019
** my_compute_square_root
** File description:
** Compute Square root
*/

int my_compute_square_root(int nb)
{
    int root = -1;
    int carre = -1;

    while (carre < nb) {
        root = root + 1;
        carre = root * root;
    }
    if (root * root == nb)
        return (root);
    else
        return (0);
}
