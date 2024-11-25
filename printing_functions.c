#include "printf.h"

/**
 * _putchar - Écrit un caractère sur la sortie standard
 * @c: caractère à imprimer
 */
void _putchar(const char c)
{
	write(1, &c, 1);
}

/**
 * _strlen - Calcule la longueur d'une chaîne
 * @str: chaîne dont la longueur doit être calculée
 * Return: taille de la chaîne
 */
int _strlen(const char *str)
{
	int i = 0;

	if (str == NULL)
		return (0);

	while (str[i] != '\0')
		i++;
	return (i);
}

/**
 * _putstr - Imprime une chaîne sur la sortie standard
 * @str: chaîne à imprimer
 */
void _putstr(const char *str)
{
	if (str == NULL)
		return;

	write(1, str, _strlen(str));
}
