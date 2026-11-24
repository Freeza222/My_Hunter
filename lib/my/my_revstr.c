/*
** EPITECH PROJECT, 2026
** dsjdjds
** File description:
** sdsjdsjd
*/

char *my_revstr(char *str)
{
    int i = 0;
    int len = 0;
    char temp;

    while (str[len] != '\0') {
        len++;
    }
    len--;
    while (i < len) {
        temp = str[i];
        str[i] = str[len];
        str[len] = temp;
        i++;
        len--;
    }
    return (str);
}
