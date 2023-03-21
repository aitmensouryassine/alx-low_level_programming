#include "main.h"
/**
 * _isalpha - check if a character is aphabetic
 * @c: The character to check
 * Return: 1 if alphabtic 0 if not
*/
int _isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
