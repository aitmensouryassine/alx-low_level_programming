#include "main.h"
#include <string.h>

/**
 * _is_palindrome - checks if a string is a palindrome
 * @s: the string to check
 * @r: the reverse string of @s
 * Return: 1 if palindrome, 0 otherwise
*/
int _is_palindrome(char *s, char *r)
{
	if (!*s)
		return (1);

	return (*s == *r && _is_palindrome(s + 1, r - 1));
}

/**
 * is_palindrome - checks if a string is a palindrome
 * @s: the string to check
 * Return: 1 if palindrome, 0 otherwise
*/
int is_palindrome(char *s)
{
	char *r = s + (strlen(s) - 1);

	return (_is_palindrome(s, r));
}
