#include "main.h"
#include <string.h>

/**
 * _strspn - gets the length of a prefix substring
 * @s: the string
 * @accept: the character to lacote
 * Return: pointer to the first occurence of the character c
 * and NULL if not found
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int len1 = strlen(s), len2 = strlen(accept), i, j;
	int found;

	for (i = 0; i < len1; i++)
	{
		found = 0;

		for (j = 0; j < len2; j++)
			if (*(s + i) == *(accept + j))
				found = 1;

		if (found == 0)
			break;
	}

	return (i);
}
