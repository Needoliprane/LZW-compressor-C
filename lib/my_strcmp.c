/*
** EPITECH PROJECT, 2018
** nf.sh
** File description:
** nf
*/

#include <stddef.h>

int my_strcmp(char const *s1, char const *s2)
{
    if (s1 == NULL || s2 == NULL)
        return (184);
    if (s1[0] == '\0' || s2[0] == '\0')
        return (184);
    for (int i = 0; s1[i]; i++) {
        if (s1[i] != s2[i])
            return (s2[i] - s1[i]);
    }
    return (0);
}