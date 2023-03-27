#include "main.h"
#include "string.h"

/**
 * puts_half - prints half of a string, followed by a new line.
 * @str: the string to print its half
 */

void puts_half(char *str)
{
	int n;

	n = strlen(str);
	n = n % 2 == 0 ? n / 2 : (n - 1) / 2;

	while (str[n] != '\0')
	{
		putchar(str[n++]);
	}
	putchar('\n');
}
