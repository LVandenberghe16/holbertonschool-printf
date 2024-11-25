#include "../main.h"

/**
 * main - Point d'entrée du programme
 *
 * Return: Toujours 0
 */
int main(void)
{
	int size;

	size = _printf("C'est %i %s %c la sauce\n", 12, 77777777, "poulet", 'o');
	printf("Taille imprimée : %d\n", size);
	return (0);
}
