#include "main.h"
/**
 * _islower - checks for lowercase character
 * @c: The character to be checked
 * Return: 0 if not lower and 1 if lower
 */
int _islower(int c)
{
	int result = c >= 'a' && c <= 'z';

	return (result);
}
