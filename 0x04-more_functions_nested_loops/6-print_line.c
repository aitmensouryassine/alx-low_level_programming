#include "main.h"

/**
 * print_line - draws a straight line in the terminal using '_'
 * followed by a new line
 * @n: the number of '_' characters
 */

void print_line(int n)
{
	int i;

	if (n > 0)
	{
		for (i = 0; i < n; i++)
		{
			_putchar('_');
		}
	}
	_putchar('\n');
}
