/*
** EPITECH PROJECT, 2026
** kdsjdsd
** File description:
** slkdlsdsld
*/

char *my_strcpy(char *dest, char const *src)
{
    int n = 0;

    while (src[n] != '\0') {
        dest[n] = src[n];
        n++;
    }
    dest[n] = '\0';
    return (dest);
}
