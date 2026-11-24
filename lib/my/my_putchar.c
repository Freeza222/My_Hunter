/*
** EPITECH PROJECT, 2026
** putchar
** File description:
** putchar vpn
*/
#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
