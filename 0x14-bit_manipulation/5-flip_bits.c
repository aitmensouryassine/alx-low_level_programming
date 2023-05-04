#include "main.h"

/**
 * flip_bits - calculates the number of bits to flip in a number
 * in order to get another number
 * @n: first number
 * @m: second number
 * Return: the number of bits to flip
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int tmp = n ^ m;
	int i = 0;
	unsigned int flips = 0;

	while (tmp)
	{
		tmp = tmp >> 1;
		i++;
	}

	while (i--)
	{
		if ((n ^ m) & 1 << i)
			flips++;
	}

	return (flips);
}
