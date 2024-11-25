#ifndef PRINTF_H
#define PRINTF_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

/**
 * struct print - structure utilisée pour suivre l'état du formatage
 * @index: position actuelle lors de l'analyse du format
 * @size: taille totale de la chaîne formatée
 * @handlers: tableau de pointeurs sur fonctions de gestion de formats
 */
typedef struct print
{
	int index;
	int size;
	void (*handlers[2])(const void *arg, struct print *data);
} print_t;

int _printf(const char *format, ...);
void print_character(const void *c, print_t *print);
void _putstr(const char *str);
int _strlen(const char *str);
void _putchar(const char c);
void print_string(const void *str, print_t *print);

#endif /* PRINTF_H */
