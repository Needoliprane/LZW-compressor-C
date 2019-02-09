/*
** EPITECH PROJECT, 2019
** LZW compressor
** File description:
** compress
*/

#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/lzw.h"

char **set_dictionary(char const *str, int const nb_elem)
{
	char **dictionary = NULL;
	int i = 0;

	if ((dictionary = malloc(sizeof(char *) * (nb_elem + 1))) == NULL)
		return (NULL);
	for (int k = 0; k <= nb_elem; k++) {
		if ((dictionary[k] = malloc(sizeof(char) * 2)) == NULL)
			return (NULL);
		for (int j = 0; j < 1; j++, dictionary[k][j] = '\0');
	}
	for (char value = 32; value < CHAR_MAX; value++) {
		if (count_para(str, value) > 0) {
			dictionary[i][0] = value;
			i++;
		}
	}
	dictionary[i] = NULL;
	return (dictionary);
}

int find_in_dictionnary(char const *str, char **dictionary)
{
	if (str == NULL)
		return (-1);
	for (int i = 0; dictionary[i]; i++) {
		if (my_strlen(dictionary[i]) > 1 && my_strcmp(str, dictionary[i]) == 0) {
			return (i);
		}
	}
	return (-1);
}

char *make_str(int dico, int dico_size)
{
	char *res = NULL;

	dico = dico - dico_size + 255 + 1;
	res = my_strcat("[", int_to_char(dico));
	res = my_strcat(res, "]");
	return (res);
}

char const *compress(char const *str, char **dictionary, int const dico_size)
{
	char *res = malloc(sizeof(char) * 3);
	char *p = malloc(sizeof(char) * 2);
	char *c = malloc(sizeof(char) * 2);
	char *pc = NULL;

	if (!res || !p || !c)
		return (NULL);
	c[1] = p[1] = res[0] = '\0';
	for (int i = 0, index_dico = 0; i < my_strlen(str);) {
		(str[i]) ? p[0] = str[i] : 0;
		(str[i + 1]) ? c[0] = str[i + 1] : 0;
		pc = my_strcat(p, c);
		if ((index_dico = find_in_dictionnary(pc, dictionary)) != -1) {
			res = my_strcat(res, make_str(index_dico, dico_size));
			i += my_strlen(pc);
		} else {
			res = my_strcat(res, p);
			i++;
		}
		dictionary = my_strcat_tab(dictionary, pc);
	}
	return (res);
}

char const *master_compress(char const *str)
{
	int nb_elem = my_count_para_tab(str);
	char **dictionary = set_dictionary(str, nb_elem);
	int dico_size = my_strlen_tab(dictionary);
	char const *res = NULL;

	if (dictionary == NULL)
		return (NULL);
	res = compress(str, dictionary, dico_size);
	return (res);
}