#include "main.h"
#include <stdlib.h>

/**
 * _realloc - reallocates a memory block using malloc and free
 * @ptr: pointer to the old allocated memory
 * @old_size: size in bytes of old allocated memory
 * @new_size: is the new size, in bytes of the new memory block
 * Return: pointer to the new allocated memory, or NULL on failure
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *newptr;
	char *oldptr = (char *)ptr;
	unsigned int n_old_ele = old_size / sizeof(char);
	unsigned int n_new_ele = new_size / sizeof(char), i = 0;

	if (old_size == new_size)
		return (ptr);

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	newptr = malloc(new_size);
	if (newptr == NULL)
		return (ptr);

	if (ptr == NULL)
		return (newptr);

	if (new_size > old_size)
	{
		while (i < n_old_ele)
		{
			*(newptr + i) = *(oldptr + i);
			i++;
		}
	}
	if (old_size > new_size)
	{
		while (i < n_new_ele)
		{
			*(newptr + i) = *(oldptr + i);
			i++;
		}
	}

	free(ptr);
	return (newptr);
}
