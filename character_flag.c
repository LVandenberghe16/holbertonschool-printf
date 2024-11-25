#include "main.h"

/**
 * print_character - Imprime un seul caractère
 * @c: caractère à imprimer
 * @data: structure contenant la taille de la chaîne générée
 */
void print_character(int c, print_t *data)
{
    if (data == NULL)
        return;

    data->size += 1;
    write(1, &c, 1);
}

/**
 * print_string - Imprime une chaîne de caractères
 * @str: chaîne à imprimer
 * @data: structure contenant la taille de la chaîne générée
 */
void print_string(const char *str, print_t *data)
{
    if (str == NULL || data == NULL)
        return;

    data->size += _strlen(str);
    _putstr(str);
}

/**
 * print_character - Imprime un seul caractère
 * @d: caractère à imprimer
 * @data: structure contenant la taille de la chaîne générée
 */
void print_double(int d, print_t *data)
{
	if (data == NULL)
		return;

	data->size += print_big_numbers(d);
}

/**
 * print_character - Imprime un seul caractère
 * @i: caractère à imprimer
 * @data: structure contenant la taille de la chaîne générée
 */
void print_integer(int i, print_t *data)
{
	if (data == NULL)
		return;

	data->size += print_numbers(i);
}	
