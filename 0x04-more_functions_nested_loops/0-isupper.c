#include "main.h"

/**
 * _isupper - checks for uppercase character
 * @c: the character to check
 * Return: Integer 1 is @c is uppercase, 0 otherwise
 */

int _isupper(int c)
{
	int isupper;

	if (c >= 'a' && c <= 'z')
	{
		isupper = 0;
	} else if (c >= 'A' && c <= 'Z')
	{
		isupper = 1;
	}

	return (isupper);
}
