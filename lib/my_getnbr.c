/*
** EPITECH PROJECT, 2018
** nf.sh
** File description:
** nf
*/

#include <unistd.h>
#include <stdlib.h>

int get_modulo(int len_nb)
{
    int modulo = 1;

    for (int i = 0; i < len_nb; i++)
        modulo *= 10;
    return (modulo);
}

int my_power(int index, int base)
{
    int value = 1;

    for (int i = 0; i < index; i++)
        value *= base;
    return (value);
}

int get_sizenb(int nb)
{
    int maxv = 1;
    int i = 0;

    for (; nb >= maxv; i++)
        maxv *= 10;
    return (i);
}

int my_getnbr(char const *str)
{
    int i = 0;
    int len_nb = 0;
    int nb = 0;
    int neg = 1;
    int count = 0;

    if (str == NULL)
        return (-84);
    for (len_nb = 0; str[len_nb] && str[len_nb] >= '0' && str[len_nb] <= '9';
        len_nb++, count++);
    if (str[0] == '-')
        neg = -1;
    for (int modulo = get_modulo(count - 1); modulo >= 0 && str[i] &&
        str[i] >= '0' && str[i] <= '9'; i++, modulo /= 10)
        nb += (str[i] - 48) * modulo;
    return (nb * neg);
}