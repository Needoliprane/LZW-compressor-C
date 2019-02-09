/*
** EPITECH PROJECT, 2019
** LZW compressor
** File description:
** master
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/lzw.h"

int error_manage_file(lzw_t *lzw)
{
	if (lzw->flag_l == true)
		return (0);
	if (lzw->path_file && lzw->flag_d == true &&
								my_strstr(lzw->path_file, ".my_lzw") == NULL) {
		return (print_error_not_c());
	}
	if (lzw->path_file && lzw->flag_c == true &&
								my_strstr(lzw->path_file, ".my_lzw") != NULL) {
		return (print_error_not_d());
	}
	return (0);
}

int print_res(lzw_t *lzw, char const *res)
{
	if (lzw->flag_l == true) {
		printf("%s\n", res);
		return (0);
	}
	if (lzw->flag_f == true && lzw->flag_c == true) {
		if (print_into_file_c(lzw, res) == 84) {
			return (84);
		}
	}
	if (lzw->flag_f == true && lzw->flag_d == true) {
		if (print_into_file_d(lzw, res) == 84) {
			return (84);
		}
	}
	return (0);
}

int master(lzw_t *lzw)
{
	char const *res = NULL;

	if (error_manage_file(lzw) == 84)
		return (84);
	if (lzw->flag_c == true && lzw->file != NULL)
		res = master_compress(lzw->file);
	if (lzw->flag_c == true && lzw->str != NULL)
		res = master_compress(lzw->str);
	if (lzw->flag_d == true && lzw->file != NULL)
		res = master_decompress(lzw->file);
	if (lzw->flag_d == true && lzw->str != NULL)
		res = master_decompress(lzw->str);
	if (res == NULL)
		return (print_error_c_d());
	print_res(lzw, res);
	free((char *)res);
	return (0);
}