#include <stddef.h>
#include <stdlib.h>
#include "function_pointers.h"

/**
 * array_iterator - executes a function given as a parameter on each
 * element of an array
 * @array: the array pointer
 * @size: size of the array
 * @action: the callback function to call on each element of the array
 */

void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t i = 0;

	if (array && size && action)
		while (i < size)
			action(array[i++]);
}
