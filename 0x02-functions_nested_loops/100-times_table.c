#include <stdio.h>
#include "main.h"
/**
 * print_times_table - prints the n times table, starting with 0.
 *
 * @n: the number of times table
 *
 * Return: nothing
 */
void print_times_table(int n)
{
	int i = 0, j, res;

	while (i <= n)
	{
		j = 0;
		while (j <= n)
		{
			res = i * j;

			if (res < 10 && j != 0)
			{
				_putchar(' ');
				_putchar(' ');
			} else if (res >= 0 && res < 100)
			{
				_putchar(' ');
			}

			printf("%d", res);

			if (j == n)
			{
				_putchar('\n');
			} else
			{
				_putchar(',');
				_putchar(' ');
			}
			j++;
		}
		i++;
	}
}
