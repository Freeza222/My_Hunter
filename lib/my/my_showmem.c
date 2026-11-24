/*
** EPITECH PROJECT, 2026
** ,sdksjdjsd
** File description:
** sdkskdsd
*/

#include "my.h"

static void put_hex(unsigned long n, int digits)
{
    char const *hex = "0123456789abcdef";

    for (int i = digits - 1; i >= 0; i--)
        my_putchar(hex[(n >> (i * 4)) & 0xF]);
}

static void put_hex_line(unsigned char const *s, int size, int start)
{
    for (int i = 0; i < 16; i++) {
        if (start + i < size)
            put_hex(s[start + i], 2);
        else {
            my_putchar(' ');
            my_putchar(' ');
        }
        if (i % 2 == 1)
            my_putchar(' ');
    }
}

static void put_text_line(unsigned char const *s, int size, int start)
{
    for (int i = 0; i < 16 && start + i < size; i++) {
        if (s[start + i] >= 32 && s[start + i] <= 126)
            my_putchar(s[start + i]);
        else
            my_putchar('.');
    }
}

int my_showmem(char const *str, int size)
{
    unsigned char const *s = (unsigned char const *)str;

    for (int start = 0; start < size; start += 16) {
        put_hex(start, 8);
        my_putchar(':');
        my_putchar(' ');
        put_hex_line(s, size, start);
        put_text_line(s, size, start);
        my_putchar('\n');
    }
    return 0;
}
