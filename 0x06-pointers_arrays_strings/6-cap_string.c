#include "main.h"
#include <string.h>

/**
 * cap_string - capitalizes all words of a string.
 * @s: a string
 * Return: pointer to the resulting string
 */

char *cap_string(char *s)
{
	int i, j, l;
	char sep[13] = " ,;.!?\"(){}\n\t";

	j = 0;
	l = strlen(s);

	for (i = 0; i < l; i++)
		for (j = 0; j < 13; j++)
			if (s[i - 1] == sep[j])
				if (s[i] >= 'a' && s[i] <= 'z')
					s[i] = s[i] - 32;

	return (s);
}
