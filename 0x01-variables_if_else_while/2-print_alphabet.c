#include <stdio.h>
/**
 * main - Entry point
 *
 * Return: Always 0
*/
int main(void)
{
	int alphabet_length = 26;
	char first_letter = 'a';
	int i = 0;

	while (i < alphabet_length)
	{
		putchar(first_letter + i);
		i++;
	}
	putchar('\n');

	return (0);
}
