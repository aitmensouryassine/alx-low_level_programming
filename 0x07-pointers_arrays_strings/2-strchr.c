#include "main.h"

/**
 * _strchr - locates a character in a string
 * @s: the string
 * @c: the character to lacote
 * Return: pointer to the first occurence of the character c
 * and NULL if not found
 */
char *_strchr(char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return (s);
		s++;
	}

	if (*s == c)
		return (s);

	return (0);
}
