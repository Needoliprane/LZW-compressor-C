/*
** EPITECH PROJECT, 2018
** nf.sh
** File description:
** nf
*/

#ifndef MY_H_
#define MY_H_

/* MACCRO */

/* LIB */

char *my_strstr(char *str, char const *to_find);
int my_count_para_tab_d(char const *str);
char *int_to_char(int nb);
int count_para_d(char const *str, char c);
char *my_evil_str(char *str);
int my_strcmp(char const *s1, char const *s2);
int my_count_para_tab(char const *str);
int count_para(char const *str, char c);
int get_sizenb(int nb);
char *my_revstr(char *str);
int my_show_word_array(char **tab);
int my_getnbr(char const *str);
char **my_str_to_word_array(char const *str);
char *check_tmp(char *tmp, char const *str);
int my_putstr(char const *str);
void free_tab(char **tab);
int my_strlen(char const *str);
char *my_strdup(char const *str);
int my_strlen_tab(char **av);
int my_put_nbr(int nb);
void my_putchar(char c);
char *my_strcat(char *buf, char *tmp);
char **my_strcat_tab(char **tab, char *str);

#endif