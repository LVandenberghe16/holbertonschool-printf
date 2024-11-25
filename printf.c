#include "printf.h"

/**
 * detect_format - Détecte le format après un caractère %
 * @str: chaîne formatée
 * @data: structure utilisée pour suivre l'état de l'analyse
 *
 * Return: le caractère après %
 */
char detect_format(const char *str, print_t *data)
{
	if (str == NULL || data == NULL)
		return ('\0');

	for (; str[data->index] != '%' && str[data->index] != '\0'; data->index += 1)
	{
		data->size += 1;
	}

	if (str[data->index] == '\0')
		return ('\0'); /* Retourne '\0' si le format est incomplet */

	return (str[data->index + 1]);
}

/**
 * init_data - Initialise la structure print_t
 * @data: structure à initialiser
 *
 * Return: un pointeur vers la structure initialisée, ou NULL en cas d'erreur
 */
print_t *init_data(print_t *data)
{
	if (data == NULL)
		return (NULL);

	data->index = 0;
	data->size = 0;

	/* Initialise les handlers */
	data->handlers[0] = print_character;
	data->handlers[1] = print_string;

	return (data);
}

/**
 * _printf - Imprime un format basé sur une chaîne
 * @format: chaîne contenant le format
 *
 * Return: la taille totale des caractères imprimés
 */
int _printf(const char *format, ...)
{
	print_t *data;
	va_list args;
	int size;
	int i;

	if (!format)
		return (-1);
	data = malloc(sizeof(print_t));
	if (!data)
		return (-1);
	data->size = 0;
	va_start(args, format);
	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			if (format[i] == 'c')
				print_character(va_arg(args, int), data);
			else if (format[i] == 's')
				print_string(va_arg(args, char *), data);
			else
				write(1, &format[i], 1), data->size++;
		}
		else
		{
			write(1, &format[i], 1);
			data->size++;
		}
	}
	va_end(args);
	size = data->size;
	free(data);
	return (size);
}
