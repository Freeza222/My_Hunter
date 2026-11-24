/*
** EPITECH PROJECT, 2026
** Uper alp
** File description:
** Only if Upper alp return 1
*/

int my_str_isupper(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] < 'A' || str[i] > 'Z')
            return 0;
        i++;
    }
    return 1;
}
