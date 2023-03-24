#include "main.h"

/**
* print_number - prints an integer using putchar
* @n: integer to print
*/

void print_number(int n)
{
	int sign, x;

	sign = n < 0 ? -1 : 1;
	x = n * sign;

	if (sign == -1)
		_putchar('-');

	if (x / 10)
	{
		print_number(x / 10);
	}
	_putchar(x % 10 + '0');
}
