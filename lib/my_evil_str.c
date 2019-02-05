/*
** EPITECH PROJECT, 2018
** nf.sh
** File description:
** nf
*/

char *my_evil_str(char *str)
{
    int len = 0;
    char tmp;

    for (; str[len]; len++);
    len--;
    for (int i = 0; i != len; i++, len--) {
        tmp = str[i];
        str[i] = str[len];
        str[len] = tmp;
    }
    return (str);
}
