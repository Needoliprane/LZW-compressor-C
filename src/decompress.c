/*
** EPITECH PROJECT, 2019
** LZW compressor
** File description:
** decompress
*/

#include <limits.h>
#include <stdlib.h>
#include "../include/lzw.h"

char **set_dictionary_d(char const *str, int const nb_elem)
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
		if (count_para_d(str, value) > 0) {
			dictionary[i][0] = value;
			i++;
		}
	}
	dictionary[i] = NULL;
	return (dictionary);
}

char const *decompress(char const *str, char **dictionary)
{
	return (str);
}


char const *master_decompress(char const *str)
{
	int nb_elem = my_count_para_tab_d(str);
	char **dictionary = set_dictionary_d(str, nb_elem);
	char const *res = NULL;

	if (dictionary == NULL)
		return (NULL);
	res = decompress(str, dictionary);
	return (res);
}