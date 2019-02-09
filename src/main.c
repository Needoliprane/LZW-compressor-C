/*
** EPITECH PROJECT, 2019
** LZW compressor
** File description:
** main
*/

#include <stdlib.h>
#include <stdio.h>
#include "../include/lzw.h"

void free_lzw(lzw_t *lzw)
{
    if (lzw->path_file != NULL)
        free(lzw->path_file);
    if (lzw->str != NULL)
        free(lzw->str);
    if (lzw->file != NULL)
        free(lzw->file);
    free(lzw);
}

int main(int ac, char **argv)
{
    lzw_t *lzw = NULL;

    if (ac != 4)
	    return (print_usage());
    if ((lzw = malloc(sizeof(lzw_t))) == NULL)
	    return (84);
    if (pars_av_memset_struct(lzw, argv + 1) == 84)
        return (84);
    if (master(lzw) == 84)
        return (84);
    free_lzw(lzw);
    return (0);
}