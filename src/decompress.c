/*
** EPITECH PROJECT, 2019
** LZW compressor
** File description:
** decompress
*/

#include <stdio.h>
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

int get_value(char const *str, int dico_size)
{
	int index_c = atoi(str);

	index_c = dico_size + (index_c - 256);
	return (index_c);
}

char **set_first_in_dictionary(char **dictionary, char *res)
{
	char *p = malloc(sizeof(char) * 2);
	char *c = malloc(sizeof(char) * 2);
	char *pc = NULL;

	p[1] = c[1] = '\0';
	for (int i = 0; res[i]; i++) {
		(res[i]) ? p[0] = res[i] : 0;
		if (res[i + 1])
			c[0] = res[i + 1];
		else
			return (dictionary);
		pc = my_strcat(p, c);
		dictionary = my_strcat_tab(dictionary, pc);
	}
	return (dictionary);
}

char *magical_strdup(char const *str, int *i)
{
	char *ret = NULL;

	for (; str[*i] != '[' && str[*i]; *i += 1);
	ret = malloc(sizeof(char) * (*i + 1));
	for (int j = 0; j <= *i; j++)
		ret[j] = str[j];
	ret[*i] = '\0';
	return (ret);
}

char const *decompress(char const *str, char **dictionary, int const dico_size)
{
	int i = 0;
	char *res = magical_strdup(str, &i);
	char *p = malloc(sizeof(char) * 2);
	char *c = malloc(sizeof(char) * 2);
	char *pc = NULL;

	if (!res || !p || !c)
		return (NULL);
	c[1] = p[1] = '\0';
	dictionary = set_first_in_dictionary(dictionary, res);
	for (int j = my_strlen(res) - 1, index = 0; i < my_strlen(str); i++, j++) {
		if (str[i] == '[') {
			index = get_value(str + i + 1, dico_size);
			for (; index >= my_strlen_tab(dictionary); index--);
			res = my_strcat(res, dictionary[index]);
			for (i++ ; str[i] && str[i] != ']'; i++);
		}
		(res[j]) ? p[0] = res[j] : 0;
		(res[j + 1]) ? c[0] = res[j + 1] : 0;
		pc = my_strcat(p, c);
		if (str[i] != '[' && str[i] != ']') {
			p[0] = str[i];
			res = my_strcat(res, p);
		}
		dictionary = my_strcat_tab(dictionary, pc);
	}
	return (res);
}


char const *master_decompress(char const *str)
{
	int nb_elem = my_count_para_tab_d(str);
	char **dictionary = set_dictionary_d(str, nb_elem);
	int dico_size = my_strlen_tab(dictionary);
	char const *res = NULL;

	if (dictionary == NULL)
		return (NULL);
	res = decompress(str, dictionary, dico_size);
	return (res);
}