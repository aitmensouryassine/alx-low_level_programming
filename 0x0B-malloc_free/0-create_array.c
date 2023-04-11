#include "main.h"
#include <stdlib.h>

/**
 * create_array - creates an array of chars, and initializes
 * it with a specific char
 * @size: size of the array
 * @c: a char
 *
 * Return: Nothing.
 */
char *create_array(unsigned int size, char c)
{
	char *arr = malloc(sizeof(char) * size);

	if (size == 0)
		return (0);

	if (arr == NULL)
		return (0);

	while (size--)
		arr[size] = c;

	return (arr);
}
