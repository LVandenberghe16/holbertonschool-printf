#ifndef PRINTF_H
#define PRINTF_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

/**
 * struct detect - a structure representing a point in 2D space
 * @index: used to define where we are when we read a string
 */
typedef struct detect
{
	int index;
} detect_t;

int _printf(const char *format, ...);
void print_character(const char c);

#endif /*PRINTF_H*/
