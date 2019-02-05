/*
** EPITECH PROJECT, 2018
** nf.sh
** File description:
** nf
*/

#include <stdlib.h>
#include <unistd.h>
#include "../include/my.h"

char *int_to_char(int nb)
{
    char print[12];
    char *ret = NULL;
    int j = 0;

    for (int i = 10, temp = 0; nb != 0; j++) {
        if ((nb % i) < 10) {
            temp = nb / i;
            print[j] = nb % i + 48;
        }
        else {
            temp = nb / i;
            print[j] = nb % i + 55;
        }
        nb = temp;
        print[j + 1] = '\0';
    }
    ret = my_strdup(print);
    return (my_evil_str(ret));
}