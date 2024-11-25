#include "../printf.h"

/**
 * main - Point d'entrée du programme
 *
 * Return: Toujours 0
 */
int main(void)
{
	int size;

	size = _printf("C'est %z la sauce\n", "oui");
	printf("Taille %z imprimée : %d\n", size);

	return (0);
}
