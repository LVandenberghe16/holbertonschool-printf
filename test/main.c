#include "../printf.h"

/**
 * main - Point d'entrée du programme
 *
 * Return: Toujours 0
 */
int main(void)
{
	int size;

	size = _printf("C'est %s la sauce\n", "oui");
	_printf("Taille imprimée : %d\n", size);

	return (0);
}
