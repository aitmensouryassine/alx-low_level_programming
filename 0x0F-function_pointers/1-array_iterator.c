#include <stddef.h>
#include <stdlib.h>
#include "function_pointers.h"

/**
 *
 *
 */

void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t i = 0;

	if (array && size && action)
		while(i < size)
			action(array[i++]);
}
