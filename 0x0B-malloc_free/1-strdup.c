#include "main.h"
#include <stdlib.h>

/**
 * _strdup -  returns a pointer to a newly allocated space in
 * memory, which contains a copy of the string given as a parameter
 * @str: the string
 *
 * Return: a pointer to the duplicated string on success,
 * and NULL on error
 */
char *_strdup(char *str)
{
	int i = 0, l = 0;
	char *copy;

	if (str == NULL)
		return (NULL);

	while (str[l] != '\0')
		l++;

	copy = (char *)malloc(sizeof(char) * (l + 1));

	if (copy == NULL)
		return (NULL);

	while (i < l)
	{
		*(copy + i) = *(str + i);
		i++;
	}
	*(copy + i) = '\0';

	return (copy);
}
