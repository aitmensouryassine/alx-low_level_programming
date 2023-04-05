#include "main.h"

/**
 * _puts_recursion - prints a string, followed by a new line.
 * @s: the string to print
*/

void _puts_recursion(char *s)
{
	while (*s)
	{
		_putchar(*s);
		s++;
	}
	_putchar('\n');
}