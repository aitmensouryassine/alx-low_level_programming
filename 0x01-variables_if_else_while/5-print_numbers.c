#include <stdio.h>
/**
 * main - Entry point
 *
 * Return: Always 0
*/
int main(void)
{
	int length = 10;
	int i = 0;

	while (i < length)
	{
		printf("%d", i);
		i++;
	}
	putchar('\n');

	return (0);
}
