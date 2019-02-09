/*
** EPITECH PROJECT, 2019
** LZW compressor
** File description:
** print_res_file
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../include/lzw.h"

char const *ext_c = ".my_lzw";
char const *ext_d = ".txt";

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

int print_into_file_c(lzw_t *lzw, char const *res)
{
	mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
	char *path = my_strcat(lzw->path_file, (char *)ext_c);
	int fd = creat(path, mode);

	if (fd == -1)
		return (print_error_create());
	if (write(fd, res, my_strlen(res)) < 0)
		return (print_error_writing());
	close(fd);
	return (0);
}

int print_into_file_d(lzw_t *lzw, char const *res)
{
	mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
	char *path = NULL;
	int fd = 0;
	int i = 0;

	for (; lzw->path_file[i] != '.' && lzw->path_file[i]; i++);
	lzw->path_file[i] = '\0';
	path = my_strcat(lzw->path_file, (char *)ext_d);
	fd = creat(path, mode);

	if (fd == -1)
		return (print_error_create());
	if (write(fd, res, my_strlen(res)) < 0)
		return (print_error_writing());
	close(fd);
	return (0);
}