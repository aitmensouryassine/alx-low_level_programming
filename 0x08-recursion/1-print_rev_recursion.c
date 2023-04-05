#include "main.h"
#include <string.h>

/**
 * print_rev_recursion - prints a string in reverse
 * @s: a string
 * @l: length of the string
*/
void print_rev_recursion(char *s, int l)
{
	if (l < 0)
		return;

	_putchar(s[l - 1]);
	print_rev_recursion(s, l - 1);
}
/**
 * _print_rev_recursion - prints a string in reverse
 * @s: a string
*/
void _print_rev_recursion(char *s)
{
	int l = strlen(s);

	print_rev_recursion(s, l);
}
