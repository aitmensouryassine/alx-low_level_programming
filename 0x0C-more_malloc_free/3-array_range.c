#include "main.h"
#include <stdlib.h>

/**
 * array_range - creates an array of integers.
 * @min: the min value
 * @max: the max value
 *
 * Return: the pointer to the newly created array,
 * or NULL on failure
 */
int *array_range(int min, int max)
{
	int *ptr;
	int i = 0;

	if (min > max)
		return (NULL);

	ptr = malloc(sizeof(*ptr) * (max - min + 1));

	if (ptr == NULL)
		return (NULL);

	while (i < (max - min + 1))
	{
		*(ptr + i) = min + i;
		i++;
	}

	return (ptr);
}
