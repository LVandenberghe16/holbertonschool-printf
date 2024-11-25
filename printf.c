#include "printf.h"

/**
 * detect_format - function to detect the format after the %
 * @str: list of types of arguments passed to the function
 * @detect: structure used to set our index in the string
 *
 * Return: the character after the %
 */
char detect_format(const char *str, detect_t *detect)
{
	for (; str[detect->index] != '%'; detect->index += 1)
	{
	}
	printf("return = %c\n index at = %i", str[detect->index + 1],
		detect->index);
	return (str[detect->index + 1]);
}


/**
 * _printf - prints anything based on a format string
 * @format: list of types of arguments passed to the function
 *
 * Return: the size of the printed string
 */
int _printf(const char *format, ...)
{
	va_list arg;
	detect_t *detect;

	int (*flag[2])(va_list, void*);
	flag[0] = print_character;
	detect = malloc(sizeof(detect_t));
	detect->index = 0;
	if (format == NULL)
		return (0);
	detect_format(format, detect);
	printf("index value = %i", detect->index);
	free(detect);
	return (0);
}
