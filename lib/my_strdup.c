/*
** EPITECH PROJECT, 2018
** nf.sh
** File description:
** nf
*/

#include <stdlib.h>
#include <limits.h>
#include "../include/my.h"

char *my_strdup(char const *src)
{
    char *dest = NULL;
    int i = 0;

    if (src == NULL)
        return (NULL);
    dest = malloc(sizeof(char) * (my_strlen(src) + 1));
    if (dest == NULL) {
        my_putstr("Error : malloc fail");
        return (NULL);
    }
    for (; dest && src[i]; i++) {
        dest[i] = src[i];
        dest[i + 1] = '\0';
    }
    return (dest);
}

int my_count_para_tab(char const *str)
{
	int nb_elem = 0;

	for (char value = 32; value < CHAR_MAX; value++)
		if (count_para(str, value) > 0)
			nb_elem++;
    return (nb_elem);
}

int my_count_para_tab_d(char const *str)
{
	int nb_elem = 0;

	for (char value = 32; value < CHAR_MAX; value++)
		if (count_para_d(str, value) > 0)
			nb_elem++;
    return (nb_elem);
}

char *my_strcat(char *buf, char *tmp)
{
    int j = 0;
    int len1 = my_strlen(buf);
    char *new_tmp = malloc(sizeof(char) * (len1 + my_strlen(tmp) + 1));

    if (new_tmp == NULL)
        return (NULL);
    for (;buf[j]; j++)
        new_tmp[j] = buf[j];
    for (int i = 0; tmp[i]; j++, i++)
        new_tmp[j] = tmp[i];
    new_tmp[j] = '\0';
    return (new_tmp);
}