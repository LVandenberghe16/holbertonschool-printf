#include "../main.h"
#include <limits.h>

/**
 * main - Point d'entrée du programme
 *
 * Return: Toujours 0
 */
int main(void)
{
    int len, len2;

    /* Test 1: Simple text */
    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    printf("Length of _printf: [%d], Length of printf: [%d]\n", len, len2);

    /* Test 2: %d and %i with integers */
    len = _printf("Integer: [%d], [%i]\n", 123, 123);
    len2 = printf("Integer: [%d], [%i]\n", 123, 123);
    printf("Length of _printf: [%d], Length of printf: [%d]\n", len, len2);

    /* Test 3: %d and %i with negative integers */
    len = _printf("Negative: [%d], [%i]\n", -456, -456);
    len2 = printf("Negative: [%d], [%i]\n", -456, -456);
    printf("Length of _printf: [%d], Length of printf: [%d]\n", len, len2);

    /* Test 4: %s with strings */
    len = _printf("String: [%s]\n", "Hello, World!");
    len2 = printf("String: [%s]\n", "Hello, World!");
    printf("Length of _printf: [%d], Length of printf: [%d]\n", len, len2);

    /* Test 5: %c with characters */
    len = _printf("Character: [%c]\n", 'A');
    len2 = printf("Character: [%c]\n", 'A');
    printf("Length of _printf: [%d], Length of printf: [%d]\n", len, len2);

    /* Test 6: %% for literal % */
    len = _printf("Percent: [%%]\n");
    len2 = printf("Percent: [%%]\n");
    printf("Length of _printf: [%d], Length of printf: [%d]\n", len, len2);

    /* Test 7: Unknown format specifiers */
    len = _printf("Unknown specifier: [%z]\n");
    len2 = printf("Unknown specifier: [%z]\n");
    printf("Length of _printf: [%d], Length of printf: [%d]\n", len, len2);

    /* Test 8: %i with float */
    len = _printf("Float as integer: [%i]\n", 3.14);
    len2 = printf("Float as integer: [%i]\n", 3.14);
    printf("Length of _printf: [%d], Length of printf: [%d]\n", len, len2);

    /* Test 9: %d and %i with very large and very small numbers */
    len = _printf("Large number: [%d], Small number: [%i]\n", INT_MAX, INT_MIN);
    len2 = printf("Large number: [%d], Small number: [%i]\n", INT_MAX, INT_MIN);
    printf("Length of _printf: [%d], Length of printf: [%d]\n", len, len2);

    /* Test 10: %s with NULL string */
    len = _printf("Null string: [%s]\n", NULL);
    len2 = printf("Null string: [%s]\n", NULL);
    printf("Length of _printf: [%d], Length of printf: [%d]\n", len, len2);

    /* Test 11: %c with invalid argument (char is expected) */
    len = _printf("Invalid char: [%c]\n", 300);  /* Outside valid char range */
    len2 = printf("Invalid char: [%c]\n", 300);  /* Outside valid char range */
    printf("Length of _printf: [%d], Length of printf: [%d]\n", len, len2);
    return (0);
}
