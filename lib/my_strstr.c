/*
** EPITECH PROJECT, 2018
** nf.sh
** File description:
** nf
*/

#include <stddef.h>

char *my_strstr(char *str, char const *to_find)
{
    int save_i = 0;
    int j = 0;

    for (int i = 0; str[i] && to_find[j]; i++) {
        if (j > 0 && str[i] == to_find[j])
            j++;
        else if (j == 0 && str[i] == to_find[j]) {
            save_i = i;
            j++;
        } else {
            save_i = 0;
            j = 0;
        }
    }
    if (save_i == 0 && j == 0)
        return (NULL);
    return (str + save_i);
}
