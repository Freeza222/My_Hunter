/*
** EPITECH PROJECT, 2026
** dkjdod
** File description:
** skdskd
*/

#include "my.h"

int my_find_prime_sup(int nb)
{
    if (nb <= 2)
        return 2;
    while (!my_is_prime(nb))
        nb++;
    return nb;
}
