#include "main.h"

/**
 * sqrt_recursion - calculates the square root of a number
 * @n: number
 * @i: iterator
 * Return: the natural square root of a number if found, if not
 * returns -1
 */
int sqrt_recursion(int n, int i)
{
	if (i == 0)
		return (-1);

	if (i * i == n)
		return (i);

	return (sqrt_recursion(n, i - 1));
}

/**
 * _sqrt_recursion - calculates the square root of a number
 * @n: number
 * Return: the natural square root of a number if found, if not
 * returns -1
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);

	if (n == 1)
		return (1);

	return (sqrt_recursion(n, n - 1));
}
