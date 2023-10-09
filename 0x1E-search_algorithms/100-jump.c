#include "search_algos.h"
#include <math.h>

/**
 *
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
