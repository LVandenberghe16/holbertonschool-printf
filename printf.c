#include "printf.h"

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

    return (data);
}

/**
 * _printf - Imprime un format basé sur une chaîne
 * @format: chaîne contenant le format
 *
 * Return: la taille totale des caractères imprimés
 */
int _printf(const char *format, ...)
{
    print_t *data;
    va_list args;
    int size;
    int i;

    if (!format)
        return (-1);
    data = malloc(sizeof(print_t));
    if (!data)
        return (-1);
    init_data(data);
    va_start(args, format);
    for (i = 0; format[i]; i++)
    {
        if (format[i] == '%' && format[i + 1])
        {
            i++;
            if (format[i] == 'c')
                data->char_handler(va_arg(args, int), data);
            else if (format[i] == 's')
                data->string_handler(va_arg(args, char *), data);
            else
            {
                write(1, &format[i - 1], 1);
                data->size++;
            }
        }
        else
        {
            write(1, &format[i], 1);
            data->size++;
        }
    }
    va_end(args);
    size = data->size;
    free(data);
    return (size);
}
