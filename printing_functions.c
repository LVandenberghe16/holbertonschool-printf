/**
 * _putchar - prints a single character, used for the c format
 * @c: a simple character
 */
void _putchar(const char c)
{
	write(1, &c, 1);
}

int _strlen(const char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}

void _putstr(const char *str)
{
    write(1, str, _strlen(str));
}
