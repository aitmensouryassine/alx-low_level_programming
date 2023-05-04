#include "main.h"

/**
 * get_bit - returns the value of a bit at a given index.
 * @n: the number
 * @index: the index of the bit
 * Return: he value of the bit at index index or -1 if an error occured
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned int div_count = 0;
	unsigned int bits = 64;

	if (index > bits)
		return (-1);

	if (n == 0)
		return (0);


	for (div_count = 0; div_count < bits; div_count++)
	{
		if (div_count == index)
			return ((n >> div_count) & 1);
	}

	return (-1);
}
