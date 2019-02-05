/*
** EPITECH PROJECT, 2019
** LZW compressor
** File description:
** lzw
*/

#ifndef LZW_H_
#define LZW_H_

/* Include */

#include <stdbool.h>
#include "./my.h"

/* Struct */

typedef struct lzw_s {
    char *str;
    char *file;
    char *path_file;
    bool flag_d;
    bool flag_c;
    bool flag_l;
    bool flag_f;
} lzw_t;

/* Pars and memset */

int pars_av_memset_struct(lzw_t *lzw, char **av);
void memset_struct(lzw_t *lzw);
int set_flag(lzw_t *lzw, char **av);
int manage_third_av(lzw_t *lzw, char *str);

/* MASTER */

int master(lzw_t *lzw);
char const *master_decompress(char const *str);
char const *master_compress(char const *str);

/* Print to file */

int print_into_file_d(lzw_t *lzw, char const *res);
int print_into_file_c(lzw_t *lzw, char const *res);

/* Get the file */

int get_fd(char const *str);
long size_to_read(char const *path);
char *my_read(int fd, char const *path);
char *get_tab(char const *str);

/* Print Usage */

int print_usage(void);
int print_error_c_d(void);

#endif /* !LZW_H_ */
