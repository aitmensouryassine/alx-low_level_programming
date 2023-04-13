#include "main.h"
#include <stdlib.h>

/**
 * _calloc - allocates memory for an array, using malloc
 * @nmemb: number of elements
 * @size: size of the element in bytes
 *
 * Return: a pointer to the allocated memory., or NULL on failure
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	void **ptr;
	unsigned int i = 0;

	if (nmemb == 0 || size == 0)
		return (NULL);

	ptr = malloc(sizeof(*ptr) * nmemb);

	if (ptr == NULL)
		return (NULL);

	while (i < nmemb)
	{
		*(ptr + i) = malloc(size);

		if (*(ptr + i) == NULL)
			return (NULL);

		*(ptr + i) = 0;

		i++;
	}

	return (ptr);
}
