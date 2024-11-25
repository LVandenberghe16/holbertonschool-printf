#include "printf.h"

/**
 * print_character - Imprime un seul caractère
 * @c: caractère à imprimer
 * @data: structure contenant la taille de la chaîne générée
 */
void print_character(const void *c, print_t *data)
{
	if (c == NULL || data == NULL)
		return;

	data->size += 1;
	write(1, (char *)c, 1);
}

/**
 * print_string - Imprime une chaîne de caractères
 * @str: chaîne à imprimer
 * @data: structure contenant la taille de la chaîne générée
 */
void print_string(const void *str, print_t *data)
{
	const char *string = (const char *)str;

	if (str == NULL || data == NULL)
		return;
	data->size += _strlen(string);
	_putstr(string);
}
