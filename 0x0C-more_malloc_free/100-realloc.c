#include "main.h"
0;10;1c#include <stdlib.h>

/**
 * _realloc - reallocates a memory block using malloc and free
 * @ptr: pointer to the old allocated memory
 * @size: size in bytes of old allocated memory
 * @new_size: is the new size, in bytes of the new memory block
 * Return:
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *newptr;
	char *oldptr = (char *)ptr;
	unsigned int n_old_ele = old_size / sizeof(char);
	unsigned int i = 0;

	if (old_size == new_size)
		return (ptr);

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	newptr = malloc(new_size);
	if (newptr == NULL)
		return (NULL);

	if (ptr == NULL)
		return (newptr);

	while (i < n_old_ele)
	{
		*(newptr + i) = *(oldptr + i);
		i++;
	}

	free(ptr);
	return (newptr);
}
