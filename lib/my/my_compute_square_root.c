/*
** EPITECH PROJECT, 2026
** jsfj
** File description:
** spdpsod
*/

int my_compute_square_root(int nb)
{
    long i = 1;

    if (nb <= 0)
        return 0;
    while (i * i < nb) {
        i++;
    }
    if (i * i == nb)
        return (int)i;
    return 0;
}
