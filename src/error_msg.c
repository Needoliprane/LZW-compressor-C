/*
** EPITECH PROJECT, 2019
** LZW compressor
** File description:
** error_msg
*/

#include <stdio.h>

int print_error_not_c(void)
{
	printf("The file is not compressed\n");
	return (84);
}

int print_error_not_d(void)
{
	printf("The file is compressed\n");
	return (84);
}

int print_error_c_d(void)
{
    printf("Error : While compressing or decompressing\n");
    return (84);
}

int print_error_create(void)
{
	printf("Error: Fail to create file\n");
	return (84);
}

int print_error_writing(void)
{
	printf("Error : not able to write on the file\n");
	return (84);
}