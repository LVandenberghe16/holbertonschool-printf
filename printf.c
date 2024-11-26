#include "main.h"

/**
 * init_data - Initialise la structure print_t
 * @data: structure à initialiser
 *
 * Return: un pointeur vers la structure initialisée, ou NULL en cas d'erreur
 */
print_t *init_data(print_t *data)
{
	if (data == NULL)
		return (NULL);

	data->size = 0;

	/* Associez directement les gestionnaires */
	data->char_handler = print_character;
	data->string_handler = print_string;
	data->double_handler = print_double;
	data->integer_handler = print_integer;

	return (data);
}

/**
 * handle_specifier - Handles a specific format specifier
 * @specifier: The format specifier character
 * @args: The variable argument list
 * @data: Pointer to the print_t structure
 * @i: used to move in the string format
 * Return: index
 */
int handle_specifier(const char *specifier, va_list args, print_t *data, int i)
{
	if (specifier[i + 1] == 'c')
	{
		data->char_handler(va_arg(args, int), data);
		i++;
	}
	else if (specifier[i + 1] == 's')
	{
		data->string_handler(va_arg(args, char *), data);
		i++;
	}
	else if (specifier[i + 1] == 'd')
	{
		data->double_handler(va_arg(args, double), data);
		i++;
	}
	else if (specifier[i + 1] == 'i')
	{
		data->integer_handler(va_arg(args, int), data);
		i++;
	}
	else if (specifier[i + 1] == '%')
	{
		_putchar('%');
		data->size++;
		i++;
	}
	else
	{
		_putchar('%');
		data->size++;
		if (specifier[i + 1] != '\0')
		{
			_putchar(specifier[i + 1]);
			data->size++;
			i++;
		}
	}
	return (i);
}

/**
 * process_format - Processes a format string and handles specifiers
 * @format: The format string
 * @args: The variable argument list
 * @data: Pointer to the print_t structure
 */
void process_format(const char *format, va_list args, print_t *data)
{
	int i;

	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%' && format[i + 1])
		{
			i = handle_specifier(format, args, data, i);
		}
		else
		{
			write(1, &format[i], 1);
			data->size++;
		}
	}
}

/**
 * _printf - Prints a formatted string
 * @format: The format string
 *
 * Return: The total number of characters printed
 */
int _printf(const char *format, ...)
{
	print_t *data;
	va_list args;
	int size;

	if (!format)
		return (-1);
	data = malloc(sizeof(print_t));
	if (!data)
		return (-1);
	init_data(data);
	va_start(args, format);
	process_format(format, args, data);
	va_end(args);
	size = data->size;
	free(data);
	return (size);
}

