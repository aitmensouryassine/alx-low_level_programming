#include "main.h"

/**
 * _is_prime_number - checks if a number is a prime number
 * @n: a number
 * @i: iterator
 * Return: 1 if prime number, 0 if not
*/
int _is_prime_number(int n, int i)
{
	if (n <= 1)
		return (0);

	if (i <= 1)
		return (1);

	if (n % i == 0 && i > 1)
		return (0);

	_is_prime_number(n, (i - 1));
}

/**
 * is_prime_number - checks if a number is a prime number
 * @n: a number
 * Return: 1 if prime number, 0 if not
*/
int is_prime_number(int n)
{
	return (_is_prime_number(n, n - 1));
}
