#include "main.h"

/**
 * print_alphabet - print alphabet followed by a new line
 * Return - nothing
 */
void print_alphabet(void)
{
	char i = 'a';

	while (i <= 'z')
	{
		_putchar(i);
		i++;
	}
	_putchar('\n');
}
