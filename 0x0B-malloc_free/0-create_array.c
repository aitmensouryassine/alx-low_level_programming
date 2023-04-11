#include "main.h"
#include <stdlib.h>

/**
 * create_array - creates an array of chars, and initializes
 * it with a specific char
 * @size: size of the array
 * @c: a char
 *
 * Return: pointer to the array (Success), NULL (Error)
 */
char *create_array(unsigned int size, char c)
{
	char *arr;

	if (size == 0)
		return (NULL);

	arr = (char *) malloc(sizeof(char) * size);

	if (arr == NULL)
		return (0);

	while (size--)
		arr[size] = c;

	return (arr);
}
