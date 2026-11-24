/*
** EPITECH PROJECT, 2026
** jjdd
** File description:
** djdjdj
*/

#include <unistd.h>
#include <stdio.h>

int my_compute_power_rec(int nb, int p)
{
    int final;

    if (p == 0)
        return 1;
    if (p < 0)
        return 0;
    return nb * my_compute_power_rec(nb, p - 1);
}
