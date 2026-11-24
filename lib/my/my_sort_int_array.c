/*
** EPITECH PROJECT, 2026
** jsjdsjdsjd
** File description:
** dskdkds
*/

#include "my.h"

#include "my.h"

static void swap_pass(int *tab, int limit)
{
    for (int j = 0; j < limit; j++) {
        if (tab[j] > tab[j + 1])
            my_swap(&tab[j], &tab[j + 1]);
    }
}

void my_sort_int_array(int *tab, int size)
{
    for (int i = 0; i < size - 1; i++)
        swap_pass(tab, size - 1 - i);
}
