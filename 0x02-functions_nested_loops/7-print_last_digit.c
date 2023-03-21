#include "main.h"
/**
 * print_last_digit - prints the last digit of a number
 * @n: integer to print its last digit
 * Return: last digit (int) of an integer
 */
int print_last_digit(int n)
{
	int sign = (n == 0) ? 0 : (n > 0) ? 1 : -1;
	int last = n % 10;

	return (last * sign);
}
