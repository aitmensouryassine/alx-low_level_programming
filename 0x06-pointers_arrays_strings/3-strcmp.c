#include "main.h"
#include <string.h>

/**
 * _strcmp - compares two strings.
 * @s1: the first string for comparision
 * @s2: the first string for comparision
 * Return: less than, equal to, or greater than ZERO
 * if @s1 is found respectively less than, match, or greater
 * than s2
 */

int _strcmp(char *s1, char *s2)
{
	int i, len;

	len = strlen(s1) >= strlen(s2) ? strlen(s1) : strlen(s2);

	for (i = 0; i <= len; i++)
	{
		if (s1[i] == s2[i])
		{
			continue;
		}
		return (s1[i] - s2[i]);
	}

	return (0);
}
