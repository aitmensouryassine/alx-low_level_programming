#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * str_concat - concatenates two strings
 * @s1: the first string
 * @s2: the second string
 *
 * Return: a pointer to the new string on success,
 * and NULL on error
 */
char *str_concat(char *s1, char *s2)
{
	int l1 = s1 == NULL ? 0 : strlen(s1);
	int l2 = s2 == NULL ? 0 : strlen(s2);
	int i = 0;
	char *str = (char *)malloc(sizeof(char) * (l1 + l2 + 1));

	if (str == NULL)
		return (NULL);

	while (i < l1)
	{
		*(str + i) = *(s1 + i);
		i++;
	}

	i = 0;
	while (i < l2)
	{
		*(str + i + l1) = *(s2 + i);
		i++;
	}
	*(str + i + l1) = '\0';

	return (str);
}
