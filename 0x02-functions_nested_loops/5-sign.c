#include "main.h"
/**
 * print_sign - determines the sign of number
 * @n: the number to check its sign
 * Return: 1 (and prints +) if n is > 0, 0 (and prints 0) if n is 0
 * -1 (and prints -) if n < 0
 */
int print_sign(int n)
{
	char res = (n == 0) ? '0' : (n > 0) ? '+' : '-';
	char val = (n == 0) ? 0 : (n > 0) ? 1 : -1;

	_putchar(res);
	return (val);
}
