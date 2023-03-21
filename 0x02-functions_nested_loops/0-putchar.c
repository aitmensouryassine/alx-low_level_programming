#include "main.h"
/**
 * main - prints _putchar, fllowd by a new linees
 * Return: Alwys 0 (Success)
 */
int main(void)
{
	char c = 'a';

	while (c <= 'z')
	{
		_putchar(c);
		c++;
	}
	_putchar('\n');
	return (0);
}
