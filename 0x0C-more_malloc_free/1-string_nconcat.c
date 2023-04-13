#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * string_nconcat - concatenates two strings.
 * @s1: the first string
 * @s2: the second string
 * @n: the number of bytes from @s2 string
 * Return: a pointer to the new string, and NULL on failure
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *ptr;
	unsigned int i = 0;
	unsigned int l1 = s1 == NULL ? 0 : strlen(s1);
	unsigned int l2 = s2 == NULL ? 0 : strlen(s2);

	l2 = n >= l2 ? l2 : n;
	ptr = malloc(sizeof(*ptr) * (l1 + l2 + 1));

	if (ptr == NULL)
		return (NULL);

	while (i < l1)
	{
		*(ptr + i) = *(s1 + i);
		i++;
	}

	i = 0;
	while (i < l2)
	{
		*(ptr + i + l1) = *(s2 + i);
		i++;
	}
	*(ptr + i + l1) = '\0';

	return (ptr);
}
