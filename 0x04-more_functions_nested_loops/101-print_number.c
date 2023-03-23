#include "main.h"

/**
* print_positive_number - prints a positive integer using putchar
* @n: integer to print
*/
void print_positive_number(int n)
{
	if (n / 10)
	{
		print_positive_number(n / 10);
	}
	_putchar(n % 10 + '0');
}

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
	print_positive_number(x);
}
