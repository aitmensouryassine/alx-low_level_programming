#include "main.h"

/**
 * _pow - calculates the power of a @base to an @exponent
 * @base: the base
 * @exp: the exponenet (not working for negative numbers)
 * Return: the result
 */
int _pow(int base, int exp)
{
	int res = 1;

	while (exp)
	{
		res *= base;
		exp--;
	}

	return (res);
}

/**
 * set_bit - sets the value of a bit to 1 at a given index
 * @n: the number
 * @index:  is the index, starting from 0 of the bit you want to set
 * Return: 1 on success, -1 on failure
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int tmp = *n;
	unsigned int div_count = 0, bits = 64;
	int number = 0;

	if (index >= bits)
		return (-1);

	while (tmp)
	{
		tmp = tmp >> 1; /* tmp = tmp / 2 */
		div_count++;
	}

	if (*n == 0 || div_count < index)
	{
		*n = *n + _pow(2, index);
		return (1);
	}

	if (div_count >= index)
	{
		while (div_count--)
		{
			if (((*n >> div_count) & 1) == 0 && div_count == index)
			{
				number += _pow(2, div_count);
			}
			if (((*n >> div_count) & 1))
			{
				number += _pow(2, div_count);
			}
		}
		*n = number;
		return (1);
	}

	return (-1);
}
