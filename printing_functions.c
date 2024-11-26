#include "main.h"

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

#include "main.h"
/**
 *print_numbers -take a number and print it
 *
 * @nb: number given to the function to print as char*
 * Return: return the size of the printed number
*/
int print_numbers(int nb)
{
	int i;
	int nb2 = nb;
	int size = 0;
	char *x;

	if (nb < 0)
	{
		_putchar('-');
		nb = nb * -1;
		nb2 = nb;
	}
	for (; nb2 != 0; size++)
		nb2 = nb2 / 10;
	x = malloc(sizeof(char) * size + 1);
	for (i = size; i != 0; i--)
	{
		x[i - 1] = (nb % 10) + '0';
		nb = nb / 10;
	}
	x[size] = '\0';
	_putstr(x);
	free(x);
	return (size);
}
