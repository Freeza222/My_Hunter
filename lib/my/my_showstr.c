/*
** EPITECH PROJECT, 2026
** dksjdskjd
** File description:
** sdjsdjsdj
*/

#include "my.h"

int my_showstr(char const *str)
{
    char const *hex = "0123456789abcdef";
    unsigned char c;

    for (int i = 0; str[i] != '\0'; i++) {
        c = (unsigned char)str[i];
        if (c >= 32 && c <= 126) {
            my_putchar(c);
        } else {
            my_putchar('\\');
            my_putchar(hex[c / 16]);
            my_putchar(hex[c % 16]);
        }
    }
    return 0;
}
