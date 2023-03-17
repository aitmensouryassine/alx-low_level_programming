#include <stdio.h>
/**
 * main - Entry point
 *
 * Return: Always 0
*/
int main(void)
{
	int length = 10;
	int zero_ascii = 48;
	int i = 0;

	while (i < length)
	{
		putchar(zero_ascii + i);
		i++;
	}
	putchar('\n');

	return (0);
}
