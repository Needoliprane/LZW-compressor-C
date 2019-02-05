/*
** EPITECH PROJECT, 2019
** LZW compressor
** File description:
** usage
*/

#include <stdio.h>

int print_usage(void)
{
    printf("Usgae : ./lwz option -[cd] -[fl] [param]\n");
    printf("\t -c\t\t: compress\n");
    printf("\t -d\t\t: decompress\n");
    printf("\t -f\t\t: file to compress or decompress\n");
    printf("\t -l\t\t: string to compress or decompress\n");
    return (84);
}

int print_error_c_d(void)
{
    printf("Error : While compressing or decompressing\n");
    return (84);
}