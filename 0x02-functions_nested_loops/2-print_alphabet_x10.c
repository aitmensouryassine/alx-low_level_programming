#include "main.h"

/**
 * print_alphabet_x10 - print alphabet 10 times
 *
 * Return: nothing
 */
void print_alphabet_x10(void)
{
	char c;
	int times = 10;
	int i = 0;

	while (i < times)
	{
		c = 'a';
		while (c <= 'z')
		{
			_putchar(c);
			c++;
		}
		_putchar('\n');
		i++;
	}
}
