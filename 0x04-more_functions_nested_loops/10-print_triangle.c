#include "main.h"

/**
 * print_triangle - draws a triangle in the terminal using '#'
 * followed by a new line
 * @size: size of the triangle
 */

void print_triangle(int size)
{
	int i, j, k, n;

	if (size > 0)
	{
		for (i = 0; i < size; i++)
		{
			n = i + 1;
			for (j = 0; j < size - n; j++)
			{
				putchar(' ');
			}
			for (k = 0; k < n; k++)
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
