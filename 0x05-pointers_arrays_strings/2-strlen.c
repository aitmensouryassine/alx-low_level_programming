#include "main.h"

/**
 * _strlen - returns the lenth of a string
 * @s: the string to return its length
 * Return: the length of th given string
 */
int _strlen(char *s)
{
	int i;
	char c;

	i = 0;
	c = s[i++];

	while (s[i] != '\0')
	{
		c = s[++i];
	}

	return (i);
}
