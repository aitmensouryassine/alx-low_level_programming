#include "main.h"
#include <string.h>

/**
 * _strncat - concatenates a string @dest with first n charcters
 * from @src string
 * @dest: first string to concatenate
 * @src: second string to append to @dest
 * @n: first n characters from @src
 * Return: pointer to the resuting string @dest
 */

char *_strncat(char *dest, char *src, int n)
{
	int i, len1;

	len1 = strlen(dest);

	for (i = 0; i < n; i++)
	{
		if (src[i] == '\0')
			break;

		dest[len1 + i] = src[i];
	}
	dest[len1 + n]  = '\0';

	return (dest);
}
