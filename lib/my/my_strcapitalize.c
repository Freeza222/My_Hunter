/*
** EPITECH PROJECT, 2026
** Capitalize
** File description:
** Capitalizes first letter of every word
*/

int is_alphabetical(char letter)
{
    if (letter >= 'a' && letter <= 'z')
        return 1;
    if (letter >= 'A' && letter <= 'Z')
        return 1;
    if (letter >= '0' && letter <= '9')
        return 1;
    return 0;
}

void boucle(char *str, int i, int *in_word)
{
    if (is_alphabetical(str[i]) == 0) {
        *in_word = 0;
        return;
    }
    if (*in_word == 0 && str[i] >= 'a' && str[i] <= 'z')
        str[i] = str[i] - 32;
    else if (*in_word == 1 && str[i] >= 'A' && str[i] <= 'Z')
        str[i] = str[i] + 32;
    *in_word = 1;
}

char *my_strcapitalize(char *str)
{
    int in_word = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        boucle(str, i, &in_word);
    }
    return str;
}
