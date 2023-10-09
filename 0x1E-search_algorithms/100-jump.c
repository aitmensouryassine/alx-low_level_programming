#include "search_algos.h"
#include <math.h>

/**
 * jump_search - searches for a value in a sorted array of integers
 * using the Jump search algorithm
 * @array: is a pointer to the first element of the array to search in
 * @size: is the number of elements in array
 * @value: is the value to search for
 * Return: The index of the search value if found, -1 otherwise
 */
int jump_search(int *array, size_t size, int value)
{
	size_t jump, i, j;

	if (!array)
		return (-1);

	jump = sqrt(size);

	for (i = 0; i < size; i += jump)
	{
		if (array[i] == value)
			return (i);

		printf("Value checked array[%ld] = [%d]\n", i, array[i]);
		if (i + jump > size)
		{
			printf("Value found between indexes [%ld] and [%ld]\n", i, i + jump);
			for (j = i; j < size; j++)
			{
				printf("Value checked array[%ld] = [%d]\n", j, array[j]);
				if (array[j] == value)
					return (j);
			}
		}
		if (array[i + jump] >= value)
		{
			printf("Value found between indexes [%ld] and [%ld]\n", i, i + jump);
			for (j = i; j <= i + jump; j++)
			{
				printf("Value checked array[%ld] = [%d]\n", j, array[j]);
				if (array[j] == value)
					return (j);
			}
		}
	}

	return (-1);
}
