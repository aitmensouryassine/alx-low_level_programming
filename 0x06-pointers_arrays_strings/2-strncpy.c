#include "main.h"
#include <string.h>

/**
 * _strncpy - copy @src string into @dest
 * @dest: the destination string
 * @src: the source string
 * @n: n characters from @src to copy
 * Return: pointer to the resuting string @dest
 */

char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}

	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}

	return (dest);
}
