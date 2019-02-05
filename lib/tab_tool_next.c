/*
** EPITECH PROJECT, 2018
** tab_tool
** File description:
** abc
*/

#include <stddef.h>
#include <stdlib.h>
#include "../include/my.h"

char *get_from_tab(char **tab, char *str)
{
    char *dst = NULL;

    for (int i = 0; tab[i]; i++) {
        if (my_strcmp(str, tab[i]) == 0) {
            dst = my_strdup(tab[i]);
            return (dst);
        }
    }
    return (NULL);
}

char **my_strcat_tab(char **tab, char *str)
{
    char **tmp_tab = NULL;
    int i = 0;
    int c = 0;

    for (; tab[i]; i++);
    tmp_tab = malloc(sizeof(char *) * (i + 2));
    if (tmp_tab == NULL)
        return (NULL);
    for (; tab[c]; c++) {
        tmp_tab[c] = my_strdup(tab[c]);
    }
    free_tab(tab);
    tmp_tab[c] = my_strdup(str);
    tmp_tab[c + 1] = NULL;
    return (tmp_tab);
}

char **remove_line(char *str, char **tab)
{
    char **tmp = NULL;
    int len = my_strlen_tab(tab);
    int i = 0;

    tmp = malloc(sizeof(char *) * (len + 1));
    if (tmp == NULL)
        return (NULL);
    for (int j = 0; tab && tab[j]; j++) {
        if (my_strcmp(str, tab[j]) != 0) {
            tmp[i] = my_strdup(tab[j]);
            i++;
        }
    }
    free_tab(tab);
    tmp[i] = NULL;
    return (tmp);
}