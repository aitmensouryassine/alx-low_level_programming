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

	for (len = strlen(s); len >= 0; len--)
	{
		putchar(s[len]);
	}

	putchar('\n');
}
