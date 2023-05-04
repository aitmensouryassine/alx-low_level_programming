#include "main.h"

/**
 * clear_bit - sets the value of a bit to 0 at a given index
 * it uses XOR
 * @n: the number to clear its bit
 * @index: index at which to set the bit to zero
 * Return: 1 on success, -1 on failure
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned int bits = 64;

	if (index >= bits)
		return (-1);

	if (*n == 0)
		return (1);

	*n = *n ^ (1 << index);
	return (1);
}
