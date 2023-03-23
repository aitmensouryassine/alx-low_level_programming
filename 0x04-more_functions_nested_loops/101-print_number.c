#include "main.h"

/**
* print_number - prints an integer using putchar
* @n: integer to print
*/

void print_number(int n)
{
	int sign;
	int x;
	int k, j;

	sign = n >= 0 ? 1 : -1;
	x = n * sign;

	if (x <= 9)
	{
		if (sign == -1)
			_putchar('-');
		_putchar(x + '0');
	} else if (x > 9 && x < 100)
	{
		if (sign == -1)
			_putchar('-');
		_putchar(x / 10 + '0');
		_putchar(x % 10 + '0');
	} else if (x >= 100 && x < 1000)
	{
		if (sign == -1)
			_putchar('-');
		k = x / 10;
		_putchar(k / 10 + '0');
		_putchar(k % 10 + '0');
		_putchar(x % 10 + '0');
	} else if (x >= 1000 && x < 10000)
	{
		if (sign == -1)
			_putchar('-');
		k = x / 10;
		j = k / 10;
		_putchar(j / 10 + '0');
		_putchar(j % 10 + '0');
		_putchar(k % 10 + '0');
		_putchar(x % 10 + '0');
	}
}
