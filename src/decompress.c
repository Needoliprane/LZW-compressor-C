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

	printf("index_c : %d\n", index_c);
	index_c = dico_size + (index_c - 256);
	return (index_c);
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
	dictionary = my_strcat_tab(dictionary, res);
	for (int j = 0, index = 0; i < my_strlen(str); i++, j++) {
		if (str[i] == '[') {
			index = get_value(str + i + 1, dico_size);
			res = my_strcat(res, dictionary[index]);
			for (i++ ; str[i] && str[i] != ']'; i++);
		}
		(res[j]) ? p[0] = res[j] : 0;
		(res[j + 1]) ? c[0] = res[j + 1] : 0;
		pc = my_strcat(p, c);
		printf("pc : %s\n", pc);
		if (str[i] != '[' && str[i] != ']') {
			printf("if : %s\n", res);
			p[0] = str[i];
			res = my_strcat(res, p);
			printf("if_n : %s\n", res);
		}
		dictionary = my_strcat_tab(dictionary, pc);
		printf("res : %s\n", res);
	}
	for (int i = 0; dictionary[i]; i++, dictionary++) {
		printf("%d : %s\n", dico_size + 255 + i, dictionary[i]);
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