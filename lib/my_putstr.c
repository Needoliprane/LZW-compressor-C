/*
** EPITECH PROJECT, 2018
** nf.sh
** File description:
** nf
*/

#include <stdlib.h>
#include <unistd.h>
#include "../include/my.h"

int count_para(char const *str, char c)
{
    int count = 0;

    for (int i = 0; str && str[i]; i++)
        if (str[i] == c)
            count++;
    return (count);
}

int count_para_d(char const *str, char c)
{
    int count = 0;

    for (int i = 0; str && str[i]; i++) {
        (str[i] == '[') ? i += 5 : 0;
        if (str[i] == c)
            count++;
    }
    return (count);
}

int my_putstr(char const *str)
{
    int i = 0;

    if (str == NULL)
        return (write(1, "--null--\n", 5));
    for (; str[i]; i++);
    write(1, str, i);
    return (0);
}

int my_show_word_array(char **tab)
{
    for (int i = 0; tab && tab[i]; i++) {
        my_putstr(tab[i]);
        my_putstr("\n");
    }
    return (0);
}

void free_tab(char **tab)
{
    for (int i = 0; tab[i]; i++)
        free(tab[i]);
    free(tab);
}