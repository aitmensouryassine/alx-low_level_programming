#include "main.h"

/**
 * print_binary - prints the binary representation of a number.
 * @n: the number to convert to binary
 */
void print_binary(unsigned long int n)
{
	unsigned long int tmp = n;
	int div_count = 0;

	while (tmp)
	{
		tmp = tmp >> 1; /* tmp = tmp / 2 */
		div_count++;
	}

	if (!div_count)
	{
		_putchar('0');
		return;
	}

	while (div_count--)
	{
		/* n % div_count == 0 */
		if (((n >> div_count) & 1) == 0)
			_putchar('0');
		else
			_putchar('1');
	}
}
