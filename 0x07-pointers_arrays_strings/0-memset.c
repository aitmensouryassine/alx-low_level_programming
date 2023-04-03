#include "main.h"

/**
 * _memset - fills memory with a constant byte
 * @s: pointer to the memory area
 * @b: constant byte
 * @n: first n bytes of the memory area
 * Return: Returns a pointer to the memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
	while (n--)
		*(s + n) = b;
}
