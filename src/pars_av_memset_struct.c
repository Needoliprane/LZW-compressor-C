/*
** EPITECH PROJECT, 2019
** LZW compressor
** File description:
** pars_av_memset_struct
*/

#include <stdio.h>
#include "../include/lzw.h"

char const *flag = "cdfl";

void memset_struct(lzw_t *lzw)
{
	lzw->flag_c = false;
	lzw->flag_d = false;
	lzw->flag_f = false;
	lzw->flag_l = false;
	lzw->file = NULL;
	lzw->str = NULL;
}

int set_flag(lzw_t *lzw, char **av)
{
	int counter_g = 0;

	for (int i = 0; i <= 1; i++) {
		if (my_strlen(av[i]) > 2 || av[i][0] != '-') {
			return (print_usage());
		}
	}
	(av[0][1] == flag[0]) ? lzw->flag_c = true, counter_g++ : 0;
	(av[0][1] == flag[1]) ? lzw->flag_d = true, counter_g++ : 0;
	(av[1][1] == flag[2]) ? lzw->flag_f = true, counter_g++ : 0;
	(av[1][1] == flag[3]) ? lzw->flag_l = true, counter_g++ : 0;
	if (counter_g != 2)
		return (print_usage());
	return (0);
}

int manage_third_av(lzw_t *lzw, char *str)
{
	if (lzw->flag_f == true) {
		lzw->path_file = my_strdup(str);
		lzw->file = get_tab(str);
	}
	if (lzw->flag_l == true)
		lzw->str = my_strdup(str);
	if (lzw->flag_l == true && lzw->str == NULL) {
		printf("Error while getting string\n");
		return (84);
	}
	if (lzw->flag_f == true && lzw->file == NULL)
		return (84);
	return (0);
}

int pars_av_memset_struct(lzw_t *lzw, char **av)
{
	memset_struct(lzw);
	if (set_flag(lzw, av) == 84)
		return (84);
	if (manage_third_av(lzw, av[2]) == 84) {
		return (84);
	}
	return (0);
}