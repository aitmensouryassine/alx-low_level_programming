#include "main.h"

/**
 * two_to_pow_of - calculate two to the power of a number
 * @n: the exponent
 * Return: the result
 */
int two_to_pow_of(int n)
{
	int res = 1;

	while (n)
	{
		res *= 2;
		n--;
	}

	return (res);
}

/**
 * binary_to_uint - converts a binary number to an unsigned int
 * @b: a char of 0s and 1s
 * Return: @b converted to unsigned int or 0 on failure
 */
unsigned int binary_to_uint(const char *b)
{
	int l = 0;
	unsigned int sum = 0;

	if (!b)
		return (0);

	while (b[l])
		l++;

	while (*b)
	{
		if (*b < '0' || *b > '9')
			return (0);

		sum += two_to_pow_of(l - 1) * (*b - '0');
		l--;
		b++;
	}

	return (sum);
}
