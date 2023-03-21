#include "main.h"
/**
 * main - prints _putchar, fllowd by a new linees
 * Return: Alwys 0 (Success)
 */
int main(void)
{
	char word[] = "_putchar";
	int i;

	for (i = 0; i <= 7; i++)
	{
		_putchar(word[i]);
	}
	_putchar('\n');
	return (0);
}
