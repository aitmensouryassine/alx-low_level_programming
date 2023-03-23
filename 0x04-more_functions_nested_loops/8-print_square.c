#include "main.h"

/**
 * print_square - draws a square in the terminal using '#'
 * followed by a new line
 * @size: size of the square
 */

void print_square(int size)
{
	int i, j;

	if (size > 0)
	{
		for (i = 0; i < size; i++)
		{
			for (j = 0; j < size; j++)
			{
				putchar('#');
			}
			putchar('\n');
		}
	} else
	{
		putchar('\n');
	}
}
