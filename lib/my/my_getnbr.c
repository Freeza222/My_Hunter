/*
** EPITECH PROJECT, 2026
** dlklkds
** File description:
** smdkskd
*/

int my_getnbr(char const *str)
{
    int i = 0;
    int sign = 1;
    long res = 0;

    while (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-')
            sign = -sign;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        res = res * 10 + (str[i] - '0');
        if (sign * res > 2147483647L || sign * res < -2147483648L)
            return 0;
        i++;
    }
    return (int)(sign * res);
}
