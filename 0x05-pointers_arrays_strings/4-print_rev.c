#include "main.h"
#include <string.h>

/**
 * print_rev - prints a string in reverse
 * @s: the string to print in reverse
 * Return: nothing
 */

void print_rev(char *s)
{
	int len;

	for (len = strlen(s) - 1; len >= 0; len--)
	{
		_putchar(s[len]);
	}

	_putchar('\n');
}
