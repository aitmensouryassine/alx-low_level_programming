#include "mian.h"

/**
 * print_alphabet_x10 - print alphabet 10 times
 *
 * Return: nothing
 */
void print_alphabet_x10(void)
{
	int times = 10;
	int i = 0;

	while (i < times)
	{
		print_alphabet();
		i++;
	}
}
