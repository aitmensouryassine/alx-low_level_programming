#include "main.h"
#include <string.h>

/**
 * string_toupper - changes all lowercase letters of a
 * string to uppercase.
 * @s: a string
 * Return: pointer to the resulting string
 */

char *string_toupper(char *s)
{
	int i, l;

	l = strlen(s);

	for (i = 0; i < l; i++)
	{
		if (s[i] >= 'a' && s[i] <= 'z')
		{
			s[i] = s[i] - 32;
		}
	}

	return (s);
}
