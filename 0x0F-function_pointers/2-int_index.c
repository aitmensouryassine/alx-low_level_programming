#include <stdlib.h>
#include "function_pointers.h"

/**
 * int_index - searches for an integer.
 * @array: the array of integers
 * @size: the size of the array
 * @cmp: the compare function pointer
 * Return: the index of the matched element (1st occurence),
 * or -1 no match found
 */

int int_index(int *array, int size, int (*cmp)(int))
{
	int i = 0;

	if (!array || !size || !cmp)
		return (-1);

	while (i < size)
	{
		if (cmp(array[i]))
			return (i);

		i++;
	}
	return (-1);
}
