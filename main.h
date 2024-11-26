#ifndef PRINTF_H
#define PRINTF_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <limits.h>

/**
 * struct print - structure utilisée pour suivre l'état du formatage
 * @size: taille totale de la chaîne formatée
 * @char_handler: oui
 * @string_handler: oui
 * @integer_handler: oui
 * @double_handler: oui
 */
typedef struct print
{
	int size;
	void (*char_handler)(int, struct print *);
	void (*string_handler)(const char *, struct print *);
	void (*integer_handler)(int, struct print *);
	void (*double_handler)(int, struct print *);
} print_t;

int _printf(const char *format, ...);
void print_character(int c, print_t *print);
void _putstr(const char *str);
int _strlen(const char *str);
void _putchar(const char c);
void print_string(const char *str, print_t *print);
void print_integer(int i, print_t *print);
void print_double(int d, print_t *print);
int print_numbers(int nb);

#endif /* PRINTF_H */
