#include "main.h"
#include "string.h"

/**
 * _strcpy - copy a string into another string
 * @dest: the destination string
 * @src: the source string
 * Return: the pointer to dest
 */

char *_strcpy(char *dest, char *src)
{
	int i, len;

	len = strlen(src);

	for (i = 0; i < len; i++)
	{
		dest[i] = src[i];
	}

	return (dest);
}
