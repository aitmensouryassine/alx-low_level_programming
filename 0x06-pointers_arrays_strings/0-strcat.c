#include "main.h"
#include <string.h>

/**
 * _strcat - concatenates two strings.
 * @dest: first string to concatenate
 * @src: second string to append to @dest
 * Return: pointer to the resuting string @dest
 */

char *_strcat(char *dest, char *src)
{
	int i, len1, len2;

	len1 = strlen(dest);
	len2 = strlen(src);

	for (i = 0; i < len2 + 1; i++)
	{
		dest[len1 + i] = src[i];
	}

	return (dest);
}
