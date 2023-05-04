#include "main.h"

/**
 * get_bit - returns the value of a bit at a given index.
 * @n: the number
 * @index: the index of the bit
 * Return: he value of the bit at index index or -1 if an error occured
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int tmp = n;
	unsigned int div_count = 0;

	if (index > 64)
		return (-1);

	while (tmp)
	{
		tmp = tmp >> 1; /* tmp = tmp / 2 */
		div_count++;
	}

	if (!div_count && index > 0)
		return (-1);

	if (!div_count && index == 0)
		return (0);

	while (div_count--)
		if (div_count == index)
			return ((n >> div_count) & 1);

	return (-1);
}
