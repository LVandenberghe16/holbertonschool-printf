#include "printf.h"

/**
 * print_character - prints a single character, used for the c format
 * @c: a simple character
 */
void print_character(const char c)
{
	write(1, &c, 1);
}
