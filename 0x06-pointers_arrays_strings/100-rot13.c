#include "main.h"
#include <string.h>

/**
 * rot13 - encodes a string using rot13.
 * @s: a string
 * Return: pointer to the resulting string
 */

char *rot13(char *s)
{
	int len, i, j;
	char rot[53] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char ebg[53] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";

	len = strlen(s);

	for (i = 0; i < len; i++)
		for (j = 0; j < 53; j++)
			if (s[i] == rot[j])
			{
				s[i] = ebg[j];
				break;
			}

	return (s);
}
