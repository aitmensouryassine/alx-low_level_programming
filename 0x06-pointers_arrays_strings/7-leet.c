#include "main.h"
#include <string.h>

/**
 * leet - encodes a string into 1337.
 * @s: a string
 * Return: pointer to the resulting string
 */

char *leet(char *s)
{
	int len, i, j;
	char l[6] = "aeotl";
	char n[6] = "43071";

	len = strlen(s);

	for (i = 0; i < len; i++)
		for (j = 0; j < 6; j++)
			if (s[i] == l[j] || s[i] == (l[j] - 32))
				s[i] = n[j];

	return (s);
}
