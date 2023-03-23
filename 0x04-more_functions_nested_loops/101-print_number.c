#include "main.h"

/**
* print_number - prints an integer using putchar
* @n: integer to print
*/

void print_number(int n)
{
	int sign = n >= 0 ? 1 : -1;
	int x = n * sign;
	int k, j, l;

	if (sign == -1)
		putchar('-');

	if (x <= 9)
	{
		putchar(x + '0');
	} else if (x > 9 && x < 100)
	{
		putchar(x / 10 + '0');
		putchar(x % 10 + '0');
	} else if (x >= 100 && x < 1000)
	{
		k = x / 10;
		putchar(k / 10 + '0');
		putchar(k % 10 + '0');
		putchar(x % 10 + '0');
	} else if (x >= 1000 && x < 10000)
	{
		k = x / 10;
		j = k / 10;
		putchar(j / 10 + '0');
		putchar(j % 10 + '0');
		putchar(k % 10 + '0');
		putchar(x % 10 + '0');
	} else if (x >= 10000 && x < 100000)
	{
		k = x / 10;
		j = k / 10;
		l = j / 10;
		putchar(l / 10 + '0');
		putchar(l % 10 + '0');
		putchar(j % 10 + '0');
		putchar(k % 10 + '0');
		putchar(x % 10 + '0');
	}
}
