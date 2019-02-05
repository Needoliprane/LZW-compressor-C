/*
** EPITECH PROJECT, 2018
** nf.sh
** File description:
** nf
*/

#include <unistd.h>
#include "../include/my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
    }
    if (nb >= 10) {
        my_put_nbr(nb / 10);
        my_putchar(nb % 10 + '0');
    }
    if (nb <= 9) {
        my_putchar(nb % 10 + '0');
    }
    return (0);
}